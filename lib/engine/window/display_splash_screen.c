/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_splash_screen.c
*/

#include "engine/struct.h"

void display_splash_screen(engine_t *engine)
{
    if (!engine->window->splash_screen->texture)
        return;
    sfRenderWindow_clear(engine->window->window, sfBlack);
    sfRenderWindow_drawSprite(engine->window->window,
        engine->window->splash_screen->sprite, NULL);
    sfRenderWindow_display(engine->window->window);
}
