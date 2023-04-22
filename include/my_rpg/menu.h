/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** menu.h
*/

#ifndef MY_RPG_MENU_H
    #define MY_RPG_MENU_H

    #include "my_rpg/struct.h"

    #define HOME_ID 0
    #define GAME_ID 1

//
// Menu
//

/**
 * @brief Clear the sub scene
 *
 * @param rpg The rpg
 */
void clear_sub_scene(rpg_t *rpg);

//
// Buttons
//

/**
 * @brief Set the button
 *
 * @param rpg The rpg
 * @param button The button
 * @param index The index of the button
 * @return sfBool False if an error occurred
 */
sfBool set_button(rpg_t *rpg, button_t *button, float index);

/**
 * @brief Update the button texture
 *
 * @param button The button
 */
void update_button_texture(button_t *button);

/**
 * @brief Create the music button
 *
 * @param rpg The rpg
 * @return button_t* The button
 */
button_t *create_music_button(rpg_t *rpg, float index);

/**
 * @brief Create the sound button
 *
 * @param rpg The rpg
 * @return button_t* The button
 */
button_t *create_sound_button(rpg_t *rpg, float index);

//
// Text
//

/**
 * @brief Create the text of the size button
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
sfBool create_size_text(rpg_t *rpg);

/**
 * @brief Update the size text
 *
 * @param rpg The rpg
 * @param button The button
 */
void update_size_text(rpg_t *rpg, button_t *button);

/**
 * @brief Create the text of the music button
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
sfBool create_music_text(rpg_t *rpg);

/**
 * @brief Update the music text
 *
 * @param rpg The rpg
 * @param button The button
 */
void update_music_text(rpg_t *rpg, button_t *button);

/**
 * @brief Create the text of the sound button
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
sfBool create_sound_text(rpg_t *rpg);

/**
 * @brief Update the sound text
 *
 * @param rpg The rpg
 * @param button The button
 */
void update_sound_text(rpg_t *rpg, button_t *button);

#endif /* !MY_RPG_MENU_H */
