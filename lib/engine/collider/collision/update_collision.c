/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_collision.c
*/

#include "engine/struct.h"
#include "engine/collision/collision.h"

sfBool is_collide(list_t *colliders, collider_t *collider)
{
    for (list_node_t *node2 = colliders->head; node2; node2 = node2->next) {
        collider_t *collider2 = node2->value;
        if (collider == collider2)
            continue;
        if (sfFloatRect_intersects(&collider->rect, &collider2->rect,
            NULL)) {
            collider->is_collide = COLLISION;
            return sfTrue;
        }
    }
    return sfFalse;
}

void update_quadtree_collision(engine_t *engine, quadtree_t *quadtree)
{
    list_t *colliders = quadtree->colliders;
    collider_t *collider = NULL;

    if (!quadtree->nw) {
        for (list_node_t *node = colliders->head; node; node = node->next) {
            collider = node->value;
            is_collide(colliders, collider);
        }
        return;
    }
    update_quadtree_collision(engine, quadtree->nw);
    update_quadtree_collision(engine, quadtree->ne);
    update_quadtree_collision(engine, quadtree->sw);
    update_quadtree_collision(engine, quadtree->se);
}

void update_collision(engine_t *engine)
{
    list_t *colliders = engine->colliders->quadtree->colliders;
    collider_t *collider = NULL;

    for (list_node_t *node = colliders->head; node; node = node->next) {
        collider = node->value;
        collider->is_collide = NO_COLLISION;
    }
    update_quadtree_collision(engine, engine->colliders->quadtree);
}
