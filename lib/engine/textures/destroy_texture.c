/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** destroy_texture.c
*/

#include <malloc.h>

#include "engine/struct.h"

void destroy_texture(texture_t *texture)
{
    sfTexture_destroy(texture->texture);
    free(texture->name);
    free(texture);
}
