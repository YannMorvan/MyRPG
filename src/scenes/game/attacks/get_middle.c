/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** get_sprite_mid.c
*/

#include <malloc.h>

#include "ice/memory.h"
#include "my_rpg/game.h"

sfVector2f get_middle(sfSprite *sprite)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);

    pos.x -= rect.width / 2;
    pos.y -= rect.height / 2;
    return pos;
}
