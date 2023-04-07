/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_monsters.c
*/

#include "my_rpg/game.h"

void update_monsters(rpg_t *rpg)
{
    list_node_t *next;

    for (list_node_t *node = GAME(rpg)->monsters->head; node; node = next) {
        next = node->next;
        ((monster_t *)node->value)->update(rpg, node->value, node);
    }
}
