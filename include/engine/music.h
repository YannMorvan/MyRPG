/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** music.h
*/

#ifndef MY_RPG_MUSIC_H
    #define MY_RPG_MUSIC_H

    #include "engine/struct.h"

/**
 * @brief Create a music object
 *
 * @param engine the engine
 * @param path the path of the music
 * @return music_t* the music
 */
music_t *create_music(engine_t *engine, char *path);

/**
 * @brief Set the volume of the music
 *
 * @param engine the engine
 * @param volume the volume
 */
void set_volume_music(engine_t *engine, float volume);

/**
 * @brief Destroy the music object
 *
 * @param engine the engine
 */
void destroy_music(engine_t *engine);

#endif /* !MY_RPG_MUSIC_H */
