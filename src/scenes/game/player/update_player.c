/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_player.c
*/

#include "my_rpg/game.h"

static void update_player_stats(player_t *player)
{
    if (player->exp >= 100) {
        player->level += 1;
        player->exp = 0;
    }
    player->intel = player->level;
}

void update_player(rpg_t *rpg)
{
    player_t *player = GAME(rpg)->player;
    list_node_t *node = list_get_node(rpg->engine->sprites,
        GAME(rpg)->player->character->sprite);

    update_player_stats(player);
    move_character(rpg->engine, player->character, player->velocity);
    if (node) {
        list_pop_node(rpg->engine->sprites, node);
        list_add_node(rpg->engine->sprites, node);
    }
}
