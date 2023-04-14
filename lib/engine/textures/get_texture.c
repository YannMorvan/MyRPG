/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** get_texture.c
*/

#include "ice/string.h"
#include "engine/struct.h"

texture_t *get_texture(engine_t *engine, char *name)
{
    list_t *textures = engine->textures;
    texture_t *texture = NULL;

    for (list_node_t *node = textures->head; node != NULL; node = node->next) {
        texture = node->value;
        if (!ice_strcmp(texture->name, name))
            return texture;
    }
    return NULL;
}
