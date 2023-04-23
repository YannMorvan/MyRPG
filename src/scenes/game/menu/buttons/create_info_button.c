/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_info_button.c
*/

#include "my_rpg.h"
#include "ice/macro.h"
#include "my_rpg/menu.h"
#include "my_rpg/home.h"

static sfBool event_info(rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(WINDOW(rpg), &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW(rpg));
        if (event.type == sfEvtKeyPressed)
            return sfFalse;
    }
    return sfTrue;
}

static void while_info(rpg_t *rpg, sprite_t *sprite)
{
    while (event_info(rpg)) {
        clear_window(rpg->engine);
        display_sprites(rpg->engine);
        sfRenderWindow_display(WINDOW(rpg));
    }
    list_remove_node(rpg->engine->sprites, sprite->node);
    destroy_sprite(sprite);
}

static void update_info_button(void *component, button_t *button)
{
    rpg_t *rpg = (rpg_t *)component;
    sfFloatRect rect;
    sprite_t *sprite;

    update_button_texture(button);
    if (button->state != CLICK)
        return;
    sprite = add_sprite_and_texture(rpg->engine, "tutorial",
        "./assets/tutorial.png");
    if (!sprite)
        return;
    sfSprite_setScale(sprite->sprite, (sfVector2f){3.25f, 3.25f});
    rect = sfSprite_getGlobalBounds(sprite->sprite);
    sfSprite_setPosition(sprite->sprite, (sfVector2f){
        ((float)rpg->engine->window->mode.width / 2) - (rect.width / 2),
        ((float)rpg->engine->window->mode.height / 2) - (rect.height / 2)
    });
    while_info(rpg, sprite);
}

button_t *create_info_button(rpg_t *rpg, float index, UNUSED int scene)
{
    button_t *button = create_button(rpg->engine, (sfVector2f){0, 0},
        "info", "./assets/buttons/info.png");

    if (!button || !set_button(rpg, button, index))
        return NULL;
    button->update = update_info_button;
    return button;
}
