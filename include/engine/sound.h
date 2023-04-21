/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** sound.h
*/

#ifndef MY_RPG_SOUND_H
    #define MY_RPG_SOUND_H

    #include "engine/struct.h"

/**
 * @brief Create a sound
 *
 * @param engine the game engine
 * @param name the name of the sound
 * @param path the path of the sound
 * @return sound_t *the sound created
 */
sound_t *create_sound(engine_t *engine, char *name, char *path);

/**
 * @brief Create the sounds
 *
 * @return sounds_t *the sounds created
 */
sounds_t *create_sounds(void);

/**
 * @brief Get the sound object
 *
 * @param engine the game engine
 * @param name the name of the sound
 * @return sound_t *the sound
 */
sound_t *get_sound(engine_t *engine, char *name);

/**
 * @brief Play a sound
 *
 * @param engine the game engine
 * @param name the name of the sound
 */
void play_sound(engine_t *engine, char *name);

/**
 * @brief Set the volume of the sounds
 *
 * @param engine the game engine
 * @param volume the volume of the sounds
 */
void set_volume_sounds(engine_t *engine, float volume);

/**
 * @brief Destroy a sound
 *
 * @param sound the sound
 */
void destroy_sound(sound_t *sound);

/**
 * @brief Destroy the sounds
 *
 * @param engine the game engine
 */
void destroy_sounds(engine_t *engine);

#endif /* !MY_RPG_SOUND_H */
