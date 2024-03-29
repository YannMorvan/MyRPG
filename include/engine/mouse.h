/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouse.h
*/

#ifndef ENGINE_MOUSE_H
    #define ENGINE_MOUSE_H

    #include "engine/struct.h"

/**
 * @brief Create a mouse object
 *
 * @param engine The engine
 * @return mouse_t* The mouse
 */
mouse_t *create_mouse(engine_t *engine);

/**
 * @brief Event of the mouse
 *
 * @param engine The engine
 * @param event The event
 * @return sfBool True if the event is handled
 */
sfBool event_mouse(engine_t *engine, sfEvent event);

/**
 * @brief Update the mouse
 *
 * @param engine The engine
 * @param mouse The mouse
 */
void update_mouse(engine_t *engine, mouse_t *mouse);

#endif /* !ENGINE_MOUSE_H */
