/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_game.c
*/

#include "ice/memory.h"
#include "my_rpg/game.h"

game_t *create_game(rpg_t *rpg)
{
    game_t *game = ice_calloc(1, sizeof(game_t));
    rpg->scene = game;

    if (!game)
        return NULL;
    game->monsters = list_create();
    game->player = create_player(rpg->engine);
    game->map = create_map(rpg);
    return (!game->monsters
        || !create_pause_button(rpg) || !create_attacks(game)) ?
        NULL : game;
}
