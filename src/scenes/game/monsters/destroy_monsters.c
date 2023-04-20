/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** destroy_monsters.c
*/

#include <malloc.h>

#include "my_rpg/game.h"

void destroy_monsters(rpg_t *rpg)
{
    list_node_t *next;

    for (list_node_t *node = GAME(rpg)->monsters->head; node; node = next) {
        next = node->next;
        destroy_monster(rpg, node->value, node);
    }
    free(GAME(rpg)->monsters);
}
