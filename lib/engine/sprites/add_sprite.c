/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** add_sprite.c
*/

#include <malloc.h>

#include "engine/texture.h"

sprite_t *add_sprite(engine_t *engine, char *name)
{
    sprite_t *new_sprite = malloc(sizeof(sprite_t));
    texture_t *texture = get_texture(engine, name);

    if (texture == NULL || new_sprite == NULL)
        return NULL;
    new_sprite->sprite = sfSprite_create();
    if (new_sprite->sprite == NULL)
        return NULL;
    sfSprite_setTexture(new_sprite->sprite, texture->texture, sfTrue);
    if (list_add(engine->sprites->sprites, new_sprite))
        return NULL;
    return new_sprite;
}
