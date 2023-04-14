/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** add_sprite.c
*/

#include <malloc.h>

#include "engine/texture.h"

sprite_t *add_sprite(engine_t *engine, char *name)
{
    sprite_t *new_sprite = malloc(sizeof(sprite_t));

    if (!new_sprite)
        return NULL;
    new_sprite->sprite = sfSprite_create();
    new_sprite->texture = get_texture(engine, name);
    if (!new_sprite->sprite || !new_sprite->texture)
        return NULL;
    sfSprite_setTexture(new_sprite->sprite, new_sprite->texture->texture,
        sfTrue);
    if (!list_add(engine->sprites, new_sprite))
        return NULL;
    new_sprite->node = engine->sprites->tail;
    return new_sprite;
}
