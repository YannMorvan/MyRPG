/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_rpg.h
*/

#ifndef MY_RPG_MY_RPG_H
    #define MY_RPG_MY_RPG_H

    #include "my_rpg/struct.h"

//
// Main functions
//

/**
 * @brief Create the rpg
 *
 * @return rpg_t* The rpg
 */
rpg_t *create_rpg(void);

/**
 * @brief Event of the rpg
 *
 * @param rpg The rpg
 */
void destroy_rpg(rpg_t *rpg);

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
 * @brief Create the game scene
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
sfBool game(void *component);

//
// Update
//

/**
 * @brief Update the button texture
 *
 * @param button The button
 */
void update_button_texture(button_t *button);

#endif /* !MY_RPG_MY_RPG_H */
