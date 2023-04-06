/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button.h
*/

#ifndef ENGINE_BUTTON_H
    #define ENGINE_BUTTON_H

    #include "engine/struct.h"

/**
 * @brief Create a button
 *
 * @param engine The engine
 * @param pos The position of the button
 * @param name The name of the button
 * @param path The path to the texture
 * @return button_t* The button
 */
button_t *create_button(engine_t *engine, sfVector2f pos,
    char *name, char *path);

/**
 * @brief Destroy the button
 *
 * @param button The button
 * @param engine The engine
 */
void update_buttons(engine_t *engine, void *component);

/**
 * @brief Destroy the button
 *
 * @param button The button
 */
void destroy_button(button_t *button);

#endif /* !ENGINE_BUTTON_H */
