/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_collider.c
*/

#include "ice/memory.h"
#include "engine/struct.h"

collider_t *create_collider(engine_t *engine, sfFloatRect rect,
    int type, collider_static_t state)
{
    collider_t *collider = ice_calloc(1, sizeof(collider_t));

    *collider = (collider_t){rect, type, COLLIDER_NONE, state, NULL};
    if (!list_add(engine->colliders, collider))
        return NULL;
    collider->node = engine->colliders->tail;
    return collider;
}
