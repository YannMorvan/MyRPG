/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** collision.h
*/

#ifndef MY_RPG_COLLISION_H
    #define MY_RPG_COLLISION_H

    #include "engine/struct.h"

    #define MAX_DEPTH 5
    #define MAX_OBJECTS 4

/**
 * @brief Create a quadtree object
 *
 * @param rect The rectangle of the quadtree
 * @return quadtree_t* The quadtree
 */
quadtree_t *create_quadtree(sfFloatRect rect, ui_t depth);

sfBool create_child_quadtree(quadtree_t *quadtree);

sfBool quadtree_insert(quadtree_t *quadtree, collider_t *collider);

/**
 * @brief Destroy the quadtree
 *
 * @param quadtree The quadtree
 * @return sfBool False if an error occurred
 */
sfBool display_quadtree(engine_t *engine);

/**
 * @brief Update the collision
 *
 * @param engine The engine
 */
void update_collision(engine_t *engine);

/**
 * @brief Display the collision
 *
 * @param engine The engine
 * @return sfBool False if an error occurred
 */
sfBool display_collision(engine_t *engine);

#endif /* !MY_RPG_COLLISION_H */
