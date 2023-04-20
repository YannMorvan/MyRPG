/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** create_attacks.c
*/

#include "my_rpg/game.h"

sfBool create_attacks(game_t *game)
{
    game->attacks = list_create();
<<<<<<< HEAD
    if (!game->attacks)
        return sfFalse;
    game->player->stats->cd[0] = 0;
    game->player->stats->cd[1] = 0;
    game->player->stats->cd[2] = 0;
    return sfTrue;
=======
    return game->attacks ? sfTrue : sfFalse;
>>>>>>> 1e7e917561e8d0655e539f0a9a3c4249a1d82b9c
}
