/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** mouse.h
*/

#ifndef MY_RPG_MOUSE_H
    #define MY_RPG_MOUSE_H

    #include "engine/struct.h"

/**
 * @brief Create a mouse object
 *
 * @param engine The engine
 * @return mouse_t* The mouse
 */
mouse_t *create_mouse(engine_t *engine);

/**
 * @brief Update the mouse
 *
 * @param engine The engine
 * @param mouse The mouse
 */
void update_mouse(engine_t *engine, mouse_t *mouse);

/**
 * @brief Destroy a mouse object
 *
 * @param mouse The mouse
 */
void destroy_mouse(mouse_t *mouse);

#endif /* !MY_RPG_MOUSE_H */
