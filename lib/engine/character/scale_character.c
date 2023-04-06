/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** scale_character.c
*/

#include "engine/struct.h"

void scale_character(character_t *character, sfVector2f scale)
{
    sfSprite_scale(character->sprite->sprite, scale);
    character->collider->rect.width *= scale.x;
    character->collider->rect.height *= scale.y;
}
