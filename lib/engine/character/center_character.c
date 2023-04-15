/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** center_character.c
*/

#include "engine/character.h"

void center_character(character_t *character)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(character->sprite->sprite);
    sfVector2f scale = sfSprite_getScale(character->sprite->sprite);
    sfVector2f pos = {rect.width / scale.x / 2, rect.height / scale.y / 2};

    sfSprite_setOrigin(character->sprite->sprite, pos);
    character->collider->rect.left -= pos.x * scale.x;
    character->collider->rect.top -= pos.y * scale.y;
}
