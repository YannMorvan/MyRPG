/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_collision.c
*/

#include "engine/struct.h"

sfBool display_collision(engine_t *engine)
{
    sfRectangleShape *rectangleShape = sfRectangleShape_create();

    if (!rectangleShape)
        return sfFalse;
    sfRectangleShape_setFillColor(rectangleShape, sfTransparent);
    sfRectangleShape_setOutlineThickness(rectangleShape, 1);
    for (list_node_t *node = engine->colliders->quadtree->colliders->head; node;
        node = node->next) {
        collider_t *collider = node->value;
        sfRectangleShape_setPosition(rectangleShape,
            (sfVector2f){collider->rect.left, collider->rect.top});
        sfRectangleShape_setSize(rectangleShape,
            (sfVector2f){collider->rect.width, collider->rect.height});
        sfRectangleShape_setOutlineColor(rectangleShape,
            (collider->is_collide == COLLISION) ? sfRed : sfGreen);
        sfRenderWindow_drawRectangleShape(engine->window->window,
            rectangleShape, NULL);
    }
    return sfTrue;
}
