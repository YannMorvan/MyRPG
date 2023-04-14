/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** destroy_sprite.c
*/

#include <malloc.h>

#include "engine/struct.h"

void destroy_sprite(sprite_t *sprite)
{
    sfSprite_destroy(sprite->sprite);
    free(sprite);
}
