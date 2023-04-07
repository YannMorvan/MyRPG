/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_splash_screen.c
*/

#include <malloc.h>

#include "engine/struct.h"

static void set_scale_splash_screen(window_t *window, ui_t scale)
{
    sfFloatRect size = sfSprite_getGlobalBounds(window->splash_screen->sprite);

    sfSprite_setScale(window->splash_screen->sprite, (sfVector2f){
        (float)scale, (float)scale});
    sfSprite_setOrigin(window->splash_screen->sprite, (sfVector2f){
        size.width / 2, size.height / 2});
    sfSprite_setPosition(window->splash_screen->sprite, (sfVector2f){
        (float)window->mode.width / 2, (float)window->mode.height / 2});
}

sfBool set_splash_screen(engine_t *engine, ui_t scale, sfColor color,
    char *path)
{
    engine->window->splash_screen = malloc(sizeof(splash_screen_t));

    if (!engine->window->splash_screen)
        return sfFalse;
    *engine->window->splash_screen = (splash_screen_t) {
        .color = color, .sprite = sfSprite_create(),
        .texture = sfTexture_createFromFile(path, NULL)
    };
    if (!engine->window->splash_screen->texture ||
        !engine->window->splash_screen->sprite)
        return sfFalse;
    sfSprite_setTexture(engine->window->splash_screen->sprite,
        engine->window->splash_screen->texture, sfTrue);
    sfRenderWindow_clear(engine->window->window, color);
    set_scale_splash_screen(engine->window, scale);
    return sfTrue;
}
