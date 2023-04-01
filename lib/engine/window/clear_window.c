/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** clear_window.c
*/

#include "engine/struct.h"

static void set_viewport(window_t *window)
{
    sfVector2u size = sfRenderWindow_getSize(window->window);
    float window_ratio = (float)size.x / (float)size.y;
    float view_ratio = (float)window->mode.width / (float)window->mode.height;
    sfFloatRect rect = {0};

    if (view_ratio < window_ratio) {
        rect.width = view_ratio / window_ratio;
        rect.height = 1.f;
        rect.left = (1.f - rect.width) / 2.f;
    } else {
        rect.height = window_ratio / view_ratio;
        rect.width = 1.f;
        rect.top = (1.f - rect.height) / 2.f;
    }
    sfView_setViewport(window->view, rect);
}

void clear_window(engine_t *engine)
{
    sfRenderWindow_clear(engine->window->window, sfBlack);
    set_viewport(engine->window);
    sfRenderWindow_setView(engine->window->window, engine->window->view);
}
