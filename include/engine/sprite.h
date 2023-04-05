/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** sprites.h
*/

#ifndef MY_RPG_SPRITE_H
    #define MY_RPG_SPRITE_H

    #include "engine/struct.h"

/**
 * @brief Add a sprite to the sprites list
 *
 * @param engine The engine
 * @param name The name of the texture
 * @return sprite_t* The sprite
 */
sprite_t *add_sprite(engine_t *engine, char *name);

/**
 * @brief Add a sprite to the sprites list
 *
 * @param engine The engine
 * @param name The name of the texture
 * @param path The path to the texture
 * @return sprite_t* The sprite
 */
sprite_t *add_sprite_and_texture(engine_t *engine, char *name, char *path);

/**
 * @brief Display all the sprites
 *
 * @param engine The engine
 */
void display_sprites(engine_t *engine);

/**
 * @brief Destroy the sprite
 *
 * @param sprite The sprite
 */
void destroy_sprite(sprite_t *sprite);

#endif /* !MY_RPG_SPRITE_H */
