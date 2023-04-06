/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_game.c
*/

#include "my_rpg/game.h"

void update_game(rpg_t *rpg)
{
    update_engine(rpg->engine, rpg);
    update_player(rpg);
    list_node_t *next;
    for (list_node_t *node = GAME(rpg)->monsters->head; node; node = next) {
        next = node->next;
        ((monster_t *)node->value)->update(rpg, node->value, node);
    }
    write_framerate(rpg->engine);
}
