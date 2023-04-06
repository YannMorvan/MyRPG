/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button.h
*/

#ifndef MY_RPG_BUTTON_H
    #define MY_RPG_BUTTON_H

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

#endif /* !MY_RPG_BUTTON_H */
