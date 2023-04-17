/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** character.h
*/

#ifndef ENGINE_CHARACTER_H
    #define ENGINE_CHARACTER_H

    #include "engine/struct.h"

/**
 * @brief Create a character object
 *
 * @param engine The engine
 * @param pos The position of the character
 * @param name The name of the texture
 * @param path The path to the texture
 */
character_t *create_character(engine_t *engine, sfVector2f pos,
    char *name, char *path);

/**
 * @brief Destroy a character object
 *
 * @param engine The engine
 * @param character The character
 * @param offset The offset
 */
void move_character(engine_t *engine, character_t *character,
    sfVector2f offset);

/**
 * @brief Destroy a character object
 *
 * @param character The character
 * @param scale The scale
 */
void scale_character(character_t *character, sfVector2f scale);

/**
 * @brief Destroy a character object
 *
 * @param character The character
 */
void center_character(character_t *character);

/**
 * @brief Set the pos character object
 *
 * @param character The character
 * @param offset The offset
 */
void set_pos_character(character_t *character, sfVector2f offset);

/**
 * @brief Destroy a character object
 *
 * @param character The character
 * @param rect The rect
 */
void set_rect_character(character_t *character, sfIntRect rect);

/**
 * @brief Destroy a character object
 *
 * @param engine The engine
 * @param character The character
 */
void destroy_character(engine_t *engine, character_t *character);

#endif /* !ENGINE_CHARACTER_H */
