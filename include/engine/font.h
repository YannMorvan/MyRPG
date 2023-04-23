/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** font.h
*/

#ifndef MY_RPG_FONT_H
    #define MY_RPG_FONT_H

    #include "engine/struct.h"

/**
 * @brief Create a font
 *
 * @param engine The engine
 * @param path The path
 * @return font_t* The font
 */
font_t *create_font(engine_t *engine, char *path);

/**
 * @brief Destroy the font
 *
 * @param font The font
 */
void destroy_font(font_t *font);

#endif /* !MY_RPG_FONT_H */
