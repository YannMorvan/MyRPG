/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** set_scale_character.c
*/

#include "engine/struct.h"

void set_scale_character(character_t *character, sfVector2f scale)
{
    sfSprite_scale(character->sprite->sprite, scale);
    character->collider->rect.width *= scale.x;
    character->collider->rect.height *= scale.y;
}
