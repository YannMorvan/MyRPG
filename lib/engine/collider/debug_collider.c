/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** debug_collider.c
*/

#include "engine/struct.h"

sfBool debug_collider(engine_t *engine)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    collider_t *collider;

    if (!rect)
        return sfFalse;
    for (list_node_t *node = engine->colliders->head; node; node = node->next) {
        collider = node->value;
        sfRectangleShape_setPosition(rect,
            (sfVector2f){collider->rect.left, collider->rect.top});
        sfRectangleShape_setSize(rect,
            (sfVector2f){collider->rect.width, collider->rect.height});
        sfRectangleShape_setFillColor(rect, (sfColor){255, 0, 0, 100});
        sfRenderWindow_drawRectangleShape(engine->window->window, rect, NULL);
    }
    sfRectangleShape_destroy(rect);
    return sfTrue;
}
