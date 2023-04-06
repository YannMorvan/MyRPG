/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_collision.c
*/

#include "engine/struct.h"

sfBool is_collide(list_t *colliders, collider_t *collider)
{
    for (list_node_t *node2 = colliders->head; node2; node2 = node2->next) {
        collider_t *collider2 = node2->value;
        if (collider == collider2)
            continue;
        if (sfFloatRect_intersects(&collider->rect, &collider2->rect,
            NULL)) {
            collider->collide |= collider2->self_type;
            collider2->collide |= collider->self_type;
            return sfTrue;
        }
    }
    return sfFalse;
}

void update_collision(engine_t *engine)
{
    for (list_node_t *node = engine->colliders->head; node; node = node->next)
        ((collider_t *)node->value)->collide = COLLIDER_NONE;
    for (list_node_t *node = engine->colliders->head; node; node = node->next)
        is_collide(engine->colliders, node->value);
}
