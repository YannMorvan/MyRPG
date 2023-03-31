/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** engine.h
*/

#ifndef MY_RPG_ENGINE_H
    #define MY_RPG_ENGINE_H

    #include "engine/struct.h"

/**
 * @brief Create the engine
 *
 * @param width The width of the window
 * @param height The height of the window
 * @param name The name of the window
 * @param style The style of the window
 * @return engine_t* The engine
 */
engine_t *create_engine(ui_t width, ui_t height,
    const char *name, sfUint32 style);

/**
 * @brief Destroy the engine
 *
 * @param engine The engine
 * @return sfBool False if an error occurred
 */
sfBool write_framerate(engine_t *engine);

#endif /* !MY_RPG_ENGINE_H */
