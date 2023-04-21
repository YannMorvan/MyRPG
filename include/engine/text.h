/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** text.h
*/

#ifndef MY_RPG_TEXT_H
    #define MY_RPG_TEXT_H

    #include "engine/struct.h"

/**
 * @brief Create a text
 *
 * @param engine The engine
 * @param name The name
 * @param str The string
 * @param pos The position
 * @return text_t* The text
 */
text_t *create_text(engine_t *engine, char *name, char *str, sfVector2f pos);

/**
 * @brief Get the text
 *
 * @param engine The engine
 * @param name The name
 * @return text_t* The text
 */
text_t *get_text(engine_t *engine, char *name);

/**
 * @brief Display the text
 *
 * @param engine The engine
 */
void display_texts(engine_t *engine);

/**
 * @brief Destroy the text
 *
 * @param text The text
 */
void destroy_text(text_t *text);

#endif /* !MY_RPG_TEXT_H */
