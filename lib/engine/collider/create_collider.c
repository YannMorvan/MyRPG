/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_collider.c
*/

#include "ice/memory.h"
#include "engine/struct.h"
#include "engine/collision/collision.h"

collider_t *create_collider(engine_t *engine, sfFloatRect rect,
    collider_static_t state)
{
    collider_t *collider = ice_calloc(1, sizeof(collider_t));

    *collider = (collider_t){rect, NO_COLLISION, state};
    quadtree_insert(engine->colliders->quadtree, collider);
    return collider;
}
