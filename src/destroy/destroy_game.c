/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_game.c
*/

#include <malloc.h>

#include "my_rpg.h"

void destroy_game(game_t *game)
{
    destroy_engine(game->engine);
    destroy_player(game->player);
    list_destroy_node(game->monsters, (void *)destroy_monster);
    free(game);
}
