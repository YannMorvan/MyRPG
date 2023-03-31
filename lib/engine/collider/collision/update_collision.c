/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_collision.c
*/

#include "engine/struct.h"

sfBool is_collide(engine_t *engine, list_t *colliders, collider_t *collider)
{
    for (list_node_t *node2 = colliders->head; node2 != NULL;
        node2 = node2->next) {
        collider_t *collider2 = node2->value;
        if (collider == collider2)
            return sfFalse;
        if (sfFloatRect_intersects(&collider->rect, &collider2->rect,
            NULL)) {
            collider->is_collide = COLLISION;
            return sfTrue;
        }
    }
    return sfFalse;
}

void update_collision(engine_t *engine)
{
    list_t *colliders = engine->colliders->colliders;
    collider_t *collider = NULL;

    for (list_node_t *node = colliders->head; node != NULL; node = node->next) {
        collider = node->value;
        collider->is_collide = NO_COLLISION;
        if (is_collide(engine, colliders, collider))
            break;
    }
}
