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
        player->intel += 1;
        player->exp = 0;
    }
    if (player->mana < 100 && player->elapsed_time >= player->wait_time)
        player->mana += 10;
    if (player->elapsed_time >= player->wait_time)
        player->elapsed_time -= player->wait_time;
}

void update_player(rpg_t *rpg)
{
    player_t *player = GAME(rpg)->player;
    list_node_t *node = list_get_node(rpg->engine->sprites,
        GAME(rpg)->player->character->sprite);

    player->elapsed_time += rpg->engine->time->delta;
    update_player_stats(player);
    move_character(rpg->engine, player->character, player->velocity);
    if (node) {
        list_pop_node(rpg->engine->sprites, node);
        list_add_node(rpg->engine->sprites, node);
    }
}
