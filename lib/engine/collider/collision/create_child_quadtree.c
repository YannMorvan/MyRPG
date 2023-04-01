/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_child_quadtree.c
*/

#include "engine/collision/collision.h"

sfBool create_child_quadtree(quadtree_t *quadtree)
{
    if (quadtree->depth >= MAX_DEPTH)
        return sfTrue;
    quadtree->nw = create_quadtree((sfFloatRect){quadtree->rect.left,
        quadtree->rect.top, quadtree->rect.width / 2,
        quadtree->rect.height / 2}, quadtree->depth + 1);
    quadtree->ne = create_quadtree((sfFloatRect){quadtree->rect.left +
        quadtree->rect.width / 2, quadtree->rect.top,
        quadtree->rect.width / 2, quadtree->rect.height / 2},
        quadtree->depth + 1);
    quadtree->sw = create_quadtree((sfFloatRect){quadtree->rect.left,
        quadtree->rect.top + quadtree->rect.height / 2,
        quadtree->rect.width / 2, quadtree->rect.height / 2},
        quadtree->depth + 1);
    quadtree->se = create_quadtree((sfFloatRect){quadtree->rect.left +
        quadtree->rect.width / 2, quadtree->rect.top +
        quadtree->rect.height / 2, quadtree->rect.width / 2,
        quadtree->rect.height / 2}, quadtree->depth + 1);
    return quadtree->nw && quadtree->ne && quadtree->sw && quadtree->se;
}
