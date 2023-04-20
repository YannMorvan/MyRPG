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
    if (!game->attacks)
        return sfFalse;
    for (int i = 0; i < 4; i++)
        game->player->stats->cd[i] = 0;
    return sfTrue;
}
