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
    if (!load_map(rpg))
        return sfFalse;
    game->hud = create_hud(rpg->engine);
//    game->player = create_player(rpg->engine);
//    if (!game->player)
//        return NULL;
    game->monsters = list_create();
    if (!game->monsters)
        return NULL;
    if (!create_pause_button(rpg))
        return NULL;
    if (!create_slime(rpg, game))
        return NULL;
    if (!create_attacks(game))
        return NULL;
    return game;
}
