/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** my_rpg.h
*/

#ifndef MY_RPG_MY_RPG_H
    #define MY_RPG_MY_RPG_H

    #include "my_rpg/struct.h"

/**
 * @brief Create the rpg
 *
 * @param debug The debug mode
 * @return rpg_t* The rpg
 */
rpg_t *create_rpg(sfBool debug);

/**
 * @brief Event of the rpg
 *
 * @param rpg The rpg
 */
void destroy_rpg(rpg_t *rpg);

//
// Parsing
//

/**
 * @brief Read a file
 *
 * @param path The path of the file
 * @return char* The content of the file
 */
char *read_file(char *path);

/**
 * @brief Parse a file
 *
 * @param path The path of the file
 * @return list_t* The list config
 */
list_t *parse_file(char *path);

/**
 * @brief Get the parse string
 *
 * @param list The list
 * @param name The name of the string
 * @return char* The string
 */
char *get_parse_string(list_t *list, char *name);

/**
 * @brief Get the parse value
 *
 * @param list The list
 * @param name The name of the value
 * @return long long The value
 */
long long get_parse_value(list_t *list, char *name);

/**
 * @brief Destroy the parse
 *
 * @param parse The parse
 */
void destroy_parse(list_t *parse);

//
// Scene
//

/**
 * @brief Create the home scene
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
sfBool home(void *component);

/**
 * @brief Create the tutorial scene
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
sfBool tutorial(void *component);

/**
 * @brief Create the game scene
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
sfBool game(void *component);

#endif /* !MY_RPG_MY_RPG_H */
