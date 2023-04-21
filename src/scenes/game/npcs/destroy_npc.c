/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** destroy_npc.c
*/

#include <malloc.h>

#include "my_rpg/game.h"

void destroy_npc(rpg_t *rpg, npc_t *npc, list_node_t *node)
{
    destroy_character(rpg->engine, npc->character);
    list_remove_node(GAME(rpg)->npcs, node);
    npc->destroy(npc);
    free(npc);
}
