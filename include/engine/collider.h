/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** collider.h
*/

#ifndef ENGINE_COLLIDER_H
    #define ENGINE_COLLIDER_H

    #include "engine/struct.h"

/**
 * @brief Create a collider object
 *
 * @param engine The engine
 * @param rect The rectangle of the collider
 * @param type The type of the collider
 * @param state The state of the collider
 * @return collider_t* The collider
 */
collider_t *create_collider(engine_t *engine, sfFloatRect rect,
    int type, collider_static_t state);

/**
 * @brief Update the collision of the colliders
 *
 * @param engine The engine
 */
void update_collision(engine_t *engine);

/**
 * @brief Destroy a collider object
 *
 * @param engine The engine
 * @param collider The collider
 */
void collider_set_type(collider_t *collider, int type);

#endif /* !ENGINE_COLLIDER_H */
