/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_engine.c
*/

#include <malloc.h>

#include "ice/string.h"
#include "engine/sprite.h"
#include "engine/collision/collision.h"

static window_t *create_window(ui_t width, ui_t height,
    const char *name, sfUint32 style)
{
    window_t *window = malloc(sizeof(window_t));

    if (!window)
        return NULL;
    window->name = ice_strdup(name);
    if (!window->name)
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
    engine->textures = malloc(sizeof(textures_t));
    engine->sprites = malloc(sizeof(sprites_t));
    engine->colliders = malloc(sizeof(colliders_t));
    engine->time = malloc(sizeof(delta_time_t));
    return engine->textures && engine->sprites && engine->colliders
        && engine->time;
}

static sfBool engine_create(engine_t *engine)
{
    engine->textures->textures = list_create();
    engine->sprites->sprites = list_create();
    engine->colliders->colliders = list_create();
    engine->colliders->quadtree = create_quadtree((sfFloatRect){0, 0,
        (float)engine->window->mode.width,
        (float)engine->window->mode.height}, 0);
    engine->time->clock = sfClock_create();
    return engine->textures->textures && engine->sprites->sprites
        && engine->colliders->colliders && engine->colliders->quadtree
        && engine->time->clock;
}

engine_t *create_engine(ui_t width, ui_t height,
    const char *name, sfUint32 style)
{
    engine_t *engine = malloc(sizeof(engine_t));

    if (!engine)
        return NULL;
    engine->window = create_window(width, height, name, style);
    if (!engine->window)
        return NULL;
    if (!engine->window || !engine_malloc(engine) || !engine_create(engine))
        return NULL;
    engine->window->view = sfView_createFromRect((sfFloatRect){0, 0,
        (float)width, (float)height});
    if (!engine->window->view)
        return NULL;
    return engine;
}
