/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_quadtree.c
*/

#include "engine/struct.h"

static void recursive_display_quadtree(sfRenderWindow *window,
    quadtree_t *quadtree, sfRectangleShape *rectangleShape)
{
    sfRectangleShape_setPosition(rectangleShape,
        (sfVector2f){quadtree->rect.left, quadtree->rect.top});
    sfRectangleShape_setSize(rectangleShape,
        (sfVector2f){quadtree->rect.width, quadtree->rect.height});
    sfRenderWindow_drawRectangleShape(window, rectangleShape, NULL);
    if (!quadtree->nw)
        return;
    recursive_display_quadtree(window, quadtree->nw, rectangleShape);
    recursive_display_quadtree(window, quadtree->ne, rectangleShape);
    recursive_display_quadtree(window, quadtree->sw, rectangleShape);
    recursive_display_quadtree(window, quadtree->se, rectangleShape);
}

sfBool display_quadtree(engine_t *engine)
{
    sfRectangleShape *rectangleShape = sfRectangleShape_create();

    if (!rectangleShape)
        return sfFalse;
    sfRectangleShape_setFillColor(rectangleShape, sfTransparent);
    sfRectangleShape_setOutlineThickness(rectangleShape, 1);
    sfRectangleShape_setOutlineColor(rectangleShape, sfBlue);
    recursive_display_quadtree(engine->window->window,
        engine->colliders->quadtree, rectangleShape);
    return sfTrue;
}
