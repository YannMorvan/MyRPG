/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** tutorial.c
*/

#include "my_rpg.h"

static sfBool create_background(rpg_t *rpg)
{
    sprite_t *background = add_sprite_and_texture(rpg->engine,
        "background", "./assets/background/dungeon.jpg");
    sfFloatRect rect;

    if (!background)
        return sfFalse;
    rect = sfSprite_getGlobalBounds(background->sprite);
    sfSprite_setScale(background->sprite, (sfVector2f){
        (float)rpg->engine->window->mode.width / rect.width,
        (float)rpg->engine->window->mode.height / rect.height
    });
    return sfTrue;
}

static sfBool create_tutorial(rpg_t *rpg)
{
    sprite_t *sprite = add_sprite_and_texture(rpg->engine,
        "tutorial", "./assets/tutorial.png");
    sfFloatRect rect;
    sfVector2u size;

    if (!sprite)
        return sfFalse;
    sfSprite_setScale(sprite->sprite, (sfVector2f){3.25f, 3.25f});
    rect = sfSprite_getGlobalBounds(sprite->sprite);
    size = sfRenderWindow_getSize(WINDOW(rpg));
    sfSprite_setPosition(sprite->sprite, (sfVector2f){
        (float)size.x / 2 - rect.width / 2,
        (float)size.y / 2 - rect.height / 2
    });
    return sfTrue;
}

static void event_tutorial(rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(WINDOW(rpg), &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW(rpg));
        if (event.type == sfEvtKeyPressed)
            rpg->engine->scene = game;
    }
}

static void display_tutorial(rpg_t *rpg)
{
    clear_window(rpg->engine);
    display_sprites(rpg->engine);
    display_texts(rpg->engine);
    sfRenderWindow_display(WINDOW(rpg));
}

sfBool tutorial(void *component)
{
    rpg_t *rpg = (rpg_t *)component;

    if (!create_background(rpg) || !create_tutorial(rpg))
        return sfFalse;
    while (scene_is_open(rpg->engine, tutorial)) {
        event_tutorial(rpg);
        display_tutorial(rpg);
    }
    return destroy_scene(rpg->engine);
}
