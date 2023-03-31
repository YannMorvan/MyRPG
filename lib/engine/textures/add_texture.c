/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** add_textures.c
*/

#include <malloc.h>

#include "engine/struct.h"

texture_t *add_texture(engine_t *engine, char *name, char *path)
{
    list_t *textures = engine->textures->textures;
    texture_t *texture = malloc(sizeof(texture_t));

    if (texture == NULL)
        return NULL;
    texture->name = name;
    texture->texture = sfTexture_createFromFile(path, NULL);
    if (texture->texture == NULL)
        return NULL;
    if (list_add(textures, texture))
        return NULL;
    return texture;
}
