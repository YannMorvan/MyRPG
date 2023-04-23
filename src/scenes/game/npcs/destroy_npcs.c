/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** destroy_npcs.c
*/

#include <malloc.h>

#include "my_rpg/game.h"

void destroy_npcs(rpg_t *rpg)
{
    list_node_t *next;

    for (list_node_t *node = GAME(rpg)->npcs->head; node; node = next) {
        next = node->next;
        destroy_npc(rpg, node->value, node);
    }
    free(GAME(rpg)->npcs);
}
