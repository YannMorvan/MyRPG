/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_player.c
*/

#include "my_rpg/game.h"

void update_player(rpg_t *rpg)
{
    player_t *player = GAME(rpg)->player;

    move_character(rpg->engine, player->character, player->velocity);
}
