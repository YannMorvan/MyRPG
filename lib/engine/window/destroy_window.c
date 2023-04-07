/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_window.c
*/

#include <malloc.h>

#include "engine/struct.h"

void destroy_window(engine_t *engine)
{
    sfRenderWindow_destroy(engine->window->window);
    sfTexture_destroy(engine->window->splash_screen->texture);
    sfSprite_destroy(engine->window->splash_screen->sprite);
    free(engine->window->splash_screen);
    sfView_destroy(engine->window->view);
    free(engine->window->name);
    if (engine->window->icon)
        sfImage_destroy(engine->window->icon);
    free(engine->window);
}
