/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** engine.h
*/

#ifndef ENGINE_ENGINE_H
    #define ENGINE_ENGINE_H

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
 * @brief Create the engine
 *
 * @param engine The engine
 * @param event The event
 * @return sfBool True if the event is handled
 */
sfBool event_engine(engine_t *engine, sfEvent event);

/**
 * @brief Update the engine
 *
 * @param engine The engine
 * @param component The component
 */
void update_engine(engine_t *engine, void *component);

/**
 * @brief Destroy the engine
 *
 * @param engine The engine
 * @return sfBool False if an error occurred
 */
sfBool write_framerate(engine_t *engine);

/**
 * @brief Destroy the engine
 *
 * @param engine The engine
 * @param path The path of the icon
 * @return sfBool False if an error occurred
 */
sfBool set_icon_engine(engine_t *engine, char *path);

/**
 * @brief Destroy the engine
 *
 * @param engine The engine
 */
void destroy_engine(engine_t *engine);

#endif /* !ENGINE_ENGINE_H */
