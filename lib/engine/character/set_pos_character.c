/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** set_pos_character.c
*/

#include "engine/struct.h"

void set_pos_character(character_t *character, sfVector2f pos)
{
    sfSprite_setPosition(character->sprite->sprite, pos);
    character->collider->rect.left += pos.x;
    character->collider->rect.top += pos.y;
}
