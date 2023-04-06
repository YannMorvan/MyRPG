/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** add_sprite_and_texture.c
*/

#include <malloc.h>

#include "engine/texture.h"

sprite_t *add_sprite_and_texture(engine_t *engine, char *name, char *path)
{
    sprite_t *new_sprite = malloc(sizeof(sprite_t));
    texture_t *texture = add_texture(engine, name, path);

    if (!texture || !new_sprite)
        return NULL;
    new_sprite->sprite = sfSprite_create();
    if (!new_sprite->sprite)
        return NULL;
    sfSprite_setTexture(new_sprite->sprite, texture->texture, sfTrue);
    if (list_add(engine->sprites->sprites, new_sprite))
        return NULL;
    return new_sprite;
}
