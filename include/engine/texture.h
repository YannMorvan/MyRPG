/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** textures.h
*/

#ifndef ENGINE_TEXTURE_H
    #define ENGINE_TEXTURE_H

    #include "engine/struct.h"

/**
 * @brief Add a texture to the textures list
 *
 * @param engine The engine
 * @param name The name of the texture
 * @param path The path to the texture
 * @return texture_t* The texture
 */
texture_t *add_texture(engine_t *engine, char *name, char *path);

/**
 * @brief Get a texture from the textures list
 *
 * @param engine The engine
 * @param name The name of the texture
 * @return texture_t* The texture
 */
texture_t *get_texture(engine_t *engine, char *name);

/**
 * @brief Destroy the texture
 *
 * @param texture The texture
 */
void destroy_texture(texture_t *texture);

#endif /* !ENGINE_TEXTURE_H */
