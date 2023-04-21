/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** update_npc.c
*/

#include "my_rpg/game.h"

void update_npcs(rpg_t *rpg)
{
    list_node_t *next;

    for (list_node_t *node = GAME(rpg)->npcs->head; node; node = next) {
        next = node->next;
        ((npc_t *)node->value)->update(rpg, node->value);
    }
}
