/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_game.c
*/

#include <malloc.h>
#include "my_rpg/game.h"

game_t *create_game(rpg_t *rpg)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    if (!load_map(rpg))
        return sfFalse;
    game->player = create_player(rpg->engine);
    if (!game->player)
        return NULL;
    game->monsters = list_create();
    if (!game->monsters)
        return NULL;
    if (!create_pause_button(rpg))
        return NULL;
    if (!create_slime(rpg, game))
        return NULL;
    return game;
}
