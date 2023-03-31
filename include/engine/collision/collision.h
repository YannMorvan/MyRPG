/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** collision.h
*/

#ifndef MY_RPG_COLLISION_H
    #define MY_RPG_COLLISION_H

    #include "engine/struct.h"

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
 * @return sfBool The state of the collision
 */
sfBool display_collision(engine_t *engine);

#endif /* !MY_RPG_COLLISION_H */
