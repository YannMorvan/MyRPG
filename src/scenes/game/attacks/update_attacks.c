/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** update_attacks.c
*/

#include "my_rpg/game.h"

void update_attacks(rpg_t *rpg)
{
    list_node_t *next;

    for (list_node_t *node = GAME(rpg)->attacks->head; node; node = next) {
        next = node->next;
        ((attack_t *)node->value)->update(rpg, node->value, node);
    }
}
