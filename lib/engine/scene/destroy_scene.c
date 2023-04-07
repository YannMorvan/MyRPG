/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_scene.c
*/

#include <malloc.h>

#include "my_rpg.h"

static sfBool engine_list_create(engine_t *engine)
{
    engine->textures = list_create();
    engine->sprites = list_create();
    engine->colliders = list_create();
    engine->buttons = list_create();
    return engine->textures && engine->sprites && engine->colliders
        && engine->buttons;
}

sfBool destroy_scene(engine_t *engine)
{
    display_splash_screen(engine);
    list_destroy_node(engine->textures, (void *)destroy_texture);
    list_destroy_node(engine->sprites, (void *)destroy_sprite);
    list_destroy_node(engine->colliders, free);
    list_destroy_node(engine->buttons, (void *)destroy_button);
    if (!engine_list_create(engine))
        return sfFalse;
    engine->mouse->collider = create_collider(engine,
        (sfFloatRect){0, 0, 5, 5},
        COLLIDER_CURSOR, MOVING);
    return engine->mouse->collider != NULL;
}
