/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** get_tile_pos.c
*/

#include "my_rpg/game.h"

sfVector2f get_tile_pos(sfVector2i pos, sfVector2i offset)
{
    sfVector2f tile_pos = {(float)(pos.x + offset.x) * 32,
        (float)(pos.y + offset.y) * 32};

    return tile_pos;
}
