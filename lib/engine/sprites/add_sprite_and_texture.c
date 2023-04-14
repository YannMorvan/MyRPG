/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** add_sprite_and_texture.c
*/

#include <malloc.h>

#include "engine/texture.h"

sprite_t *add_sprite_and_texture(engine_t *engine, char *name, char *path)
{
    sprite_t *new_sprite = malloc(sizeof(sprite_t));

    if (!new_sprite)
        return NULL;
    new_sprite->sprite = sfSprite_create();
    new_sprite->texture = add_texture(engine, name, path);
    if (!new_sprite->sprite || !new_sprite->texture)
        return NULL;
    sfSprite_setTexture(new_sprite->sprite, new_sprite->texture->texture,
        sfTrue);
    if (!list_add(engine->sprites, new_sprite))
        return NULL;
    new_sprite->node = engine->sprites->tail;
    return new_sprite;
}
