/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** home.h
*/

#ifndef MY_RPG_HOME_H
    #define MY_RPG_HOME_H

    #include "my_rpg/struct.h"

//
// Main functions
//

/**
 * @brief Create the home scene
 *
 * @param rpg The rpg
 */
sfBool create_home(rpg_t *rpg);

/**
 * @brief Event of the home scene
 *
 * @param rpg The rpg
 */
void event_home(rpg_t *rpg);

/**
 * @brief Update the home scene
 *
 * @param rpg The rpg
 */
void update_home(rpg_t *rpg);

/**
 * @brief Display the home scene
 *
 * @param rpg The rpg
 */
void display_home(rpg_t *rpg);

/**
 * @brief Destroy the home scene
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
sfBool destroy_home(rpg_t *rpg);

//
// Button
//

/**
 * @brief Create the buttons of the home scene
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
sfBool create_buttons(rpg_t *rpg);

/**
 * @brief Create the new button
 *
 * @param rpg The rpg
 * @return button_t* The button
 */
button_t *create_new_button(rpg_t *rpg, float index);

/**
 * @brief Create the start button
 *
 * @param rpg The rpg
 * @return button_t* The button
 */
button_t *create_start_button(rpg_t *rpg, float index);

#endif /* !MY_RPG_HOME_H */
