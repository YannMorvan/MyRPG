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
// Struct
//

typedef enum home_scene_s {
    HOME_MENU = 0,
    HOME_SETTINGS = 1
} home_scene_t;

typedef struct home_s {
    int size_index;
    home_scene_t scene;
    sfBool (*create_sub_scene)(rpg_t *rpg);
} home_t;

    #define HOME(rpg) ((home_t *)rpg->scene)

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
// Menu
//

/**
 * @brief Load the background of the home scene
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
sfBool load_background(rpg_t *rpg);

//
// Button
//

/**
 * @brief Create the buttons of the home scene
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
sfBool create_buttons_home(rpg_t *rpg);

/**
 * @brief Create the buttons of the settings scene
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
sfBool create_buttons_settings(rpg_t *rpg);

/**
 * @brief Create the start button
 *
 * @param rpg The rpg
 * @param scene The id of the scene
 * @return button_t* The button
 */
button_t *create_start_button(rpg_t *rpg, float index, int scene);

#endif /* !MY_RPG_HOME_H */
