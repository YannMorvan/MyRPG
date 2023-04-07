/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_rect_character.c
*/

#include "engine/struct.h"

void set_rect_character(character_t *character, sfIntRect rect)
{
    sfVector2f scale = sfSprite_getScale(character->sprite->sprite);

    sfSprite_setTextureRect(character->sprite->sprite, rect);
    character->collider->rect.width = (float)rect.width * scale.x;
    character->collider->rect.height = (float)rect.height * scale.y;
}
