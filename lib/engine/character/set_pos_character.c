/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** set_pos_character.c
*/

#include "engine/struct.h"

void set_pos_character(character_t *character, sfVector2f offset)
{
    sfSprite_move(character->sprite->sprite, offset);
    character->collider->rect.left += offset.x;
    character->collider->rect.top += offset.y;
}
