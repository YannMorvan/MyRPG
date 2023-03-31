/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** character.h
*/

#ifndef MY_RPG_CHARACTER_H
    #define MY_RPG_CHARACTER_H

    #include "engine/struct.h"

/**
 * @brief Create a character object
 *
 * @param engine The engine
 * @param pos The position of the character
 * @param name The name of the character
 * @param path The path to the texture
 */
character_t *create_character(engine_t *engine, sfVector2f pos,
    char *name, char *path);

#endif /* !MY_RPG_CHARACTER_H */
