/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** move_character.c
*/

#include "engine/struct.h"

void move_character(engine_t *engine, character_t *character, sfVector2f offset)
{
    offset.x *= engine->time->delta;
    offset.y *= engine->time->delta;

    sfSprite_move(character->sprite->sprite, offset);
    character->collider->rect.left += offset.x;
    character->collider->rect.top += offset.y;
}
