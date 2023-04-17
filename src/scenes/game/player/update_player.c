/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_player.c
*/

#include "my_rpg/game.h"

void update_player(rpg_t *rpg)
{
    player_t *player = GAME(rpg)->player;
    list_node_t *node = list_get_node(rpg->engine->sprites,
        GAME(rpg)->player->character->sprite);

    move_character(rpg->engine, player->character, player->velocity);
    if (node) {
        list_pop_node(rpg->engine->sprites, node);
        list_add_node(rpg->engine->sprites, node);
    }
}
