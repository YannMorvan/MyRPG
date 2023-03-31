/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** collider.h
*/

#ifndef MY_RPG_COLLIDER_H
    #define MY_RPG_COLLIDER_H

    #include "engine/struct.h"

/**
 * @brief Create a collider object
 *
 * @param engine The engine
 * @param rect The rectangle of the collider
 * @param state The state of the collider
 * @return collider_t* The collider
 */
collider_t *create_collider(engine_t *engine, sfFloatRect rect,
    collider_static_t state);

#endif /* !MY_RPG_COLLIDER_H */
