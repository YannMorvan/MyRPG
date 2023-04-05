/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_player.c
*/

#include <malloc.h>

#include "my_rpg.h"

void destroy_player(player_t *player)
{
    free(player->character);
    free(player);
}
