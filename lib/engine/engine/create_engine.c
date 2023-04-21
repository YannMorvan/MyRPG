/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_engine.c
*/

#include <malloc.h>

#include "ice/memory.h"
#include "ice/string.h"
#include "engine/mouse.h"

static window_t *create_window(ui_t width, ui_t height,
    const char *name, sfUint32 style)
{
    window_t *window = malloc(sizeof(window_t));

    if (!window)
        return NULL;
    window->name = ice_strdup(name);
    if (!window->name)
        return NULL;
    window->view = sfView_createFromRect((sfFloatRect){0, 0,
        (float)width, (float)height});
    if (!window->view)
        return NULL;
    window->mode = (sfVideoMode){width, height, 32};
    window->window = sfRenderWindow_create(window->mode, window->name,
        style, NULL);
    if (!window->window)
        return NULL;
    return window;
}

static sfBool engine_malloc(engine_t *engine)
{
    engine->time = malloc(sizeof(delta_time_t));
    return engine->time != NULL;
}

static sfBool engine_create(engine_t *engine)
{
    engine->textures = list_create();
    engine->sprites = list_create();
    engine->colliders = list_create();
    engine->buttons = list_create();
    engine->fonts = list_create();
    engine->texts = list_create();
    engine->time->clock = sfClock_create();
    engine->mouse = create_mouse(engine);
    return engine->textures && engine->sprites && engine->colliders
        && engine->buttons && engine->fonts && engine->texts
        && engine->time->clock && engine->mouse;
}

engine_t *create_engine(ui_t width, ui_t height,
    const char *name, sfUint32 style)
{
    engine_t *engine = ice_calloc(1, sizeof(engine_t));

    if (!engine || !engine_malloc(engine) || !engine_create(engine))
        return NULL;
    engine->window = create_window(width, height, name, style);
    if (!engine->window)
        return NULL;
    return engine;
}
