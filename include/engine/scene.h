/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** scene.h
*/

#ifndef ENGINE_SCENE_H
    #define ENGINE_SCENE_H

    #include "engine/struct.h"

/**
 * @brief Destroy the scene object
 *
 * @param engine The engine
 * @return sfBool False if an error occurred
 */
sfBool destroy_scene(engine_t *engine);

/**
 * @brief Open the scene
 *
 * @param engine The engine
 * @param scene The scene
 * @return sfBool False if an error occurred
 */
sfBool scene_is_open(engine_t *engine, sfBool (*scene)(void *component));

#endif /* !ENGINE_SCENE_H */
