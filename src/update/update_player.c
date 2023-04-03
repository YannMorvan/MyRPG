/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_player.c
*/

#include "my_rpg.h"

void update_player(game_t *game)
{
    move_character(game->engine, game->player->character,
        game->player->velocity);
}
