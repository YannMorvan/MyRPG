/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_character.c
*/

#include <malloc.h>

#include "engine/sprite.h"
#include "engine/texture.h"
#include "engine/collider.h"

character_t *create_character(engine_t *engine, sfVector2f pos,
    char *name, char *path)
{
    character_t *character = malloc(sizeof(character_t));
    sfFloatRect rect;

    if (!character)
        return NULL;
    if (!get_texture(engine, name))
        character->sprite = add_sprite_and_texture(engine, name, path);
    else
        character->sprite = add_sprite(engine, name);
    if (!character->sprite)
        return NULL;
    sfSprite_setPosition(character->sprite->sprite, pos);
    rect = sfSprite_getGlobalBounds(character->sprite->sprite);
    character->collider = create_collider(engine, rect, COLLIDER_NONE, MOVING);
    if (!character->collider)
        return NULL;
    return character;
}
