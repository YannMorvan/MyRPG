/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_engine.c
*/

#include <malloc.h>

#include "engine/sprite.h"

static sfBool engine_malloc(engine_t *engine)
{
    engine->textures = malloc(sizeof(textures_t));
    engine->sprites = malloc(sizeof(sprites_t));
    engine->colliders = malloc(sizeof(colliders_t));
    engine->time = malloc(sizeof(delta_time_t));
    return !engine->textures || !engine->sprites || !engine->colliders
        || !engine->time;
}

static sfBool engine_create(engine_t *engine)
{
    engine->textures->textures = list_create();
    engine->sprites->sprites = list_create();
    engine->colliders->colliders = list_create();
    engine->time->clock = sfClock_create();
    return !engine->textures->textures || !engine->sprites->sprites
        || !engine->colliders->colliders || !engine->time->clock;
}

engine_t *create_engine(ui_t width, ui_t height,
    const char *name, sfUint32 style)
{
    engine_t *engine = malloc(sizeof(engine_t));

    if (!engine)
        return NULL;
    engine->window = sfRenderWindow_create(
        (sfVideoMode){width, height, 32},
        name, style, NULL);
    if (!engine->window || engine_malloc(engine) || engine_create(engine))
        return NULL;
    return engine;
}
