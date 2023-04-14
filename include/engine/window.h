/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** window.h
*/

#ifndef ENGINE_WINDOW_H
    #define ENGINE_WINDOW_H

    #include "engine/struct.h"

/**
 * @brief Clear the window and update the responsive of the window
 *
 * @param engine The engine
 */
void clear_window(engine_t *engine);

/**
 * @brief Create a window
 *
 * @param engine The engine
 * @param name The name of the window
 * @param width The width of the window
 * @param height The height of the window
 * @return sfBool False if an error occurred
 */
sfBool set_splash_screen(engine_t *engine, ui_t scale, sfColor color,
    char *path);

/**
 * @brief Draw the splash screen
 *
 * @param engine The engine
 */
void display_splash_screen(engine_t *engine);

/**
 * @brief Destroy the window
 *
 * @param engine The engine
 */
void destroy_window(engine_t *engine);

#endif /* !ENGINE_WINDOW_H */
