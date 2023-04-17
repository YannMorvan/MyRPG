/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** get_angle.c
*/

#include <malloc.h>
#include <math.h>

#include "ice/memory.h"
#include "my_rpg/game.h"

double get_angle(sfVector2f player_pos, sfVector2f target)
{
    sfVector2f direction = (sfVector2f){target.x -
        player_pos.x, target.y - player_pos.y};

    return (atan2(direction.y, direction.x));
}
