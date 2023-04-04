/*
** EPITECH PROJECT, 2022
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

    *collider = (collider_t){rect, type, COLLIDER_NONE, NO_COLLISION, state};
    list_add(engine->colliders->colliders, collider);
    return collider;
}
