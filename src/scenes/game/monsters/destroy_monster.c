/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** destroy_monster.c
*/

#include <malloc.h>

#include "my_rpg/game.h"

void destroy_monster(rpg_t *rpg, monster_t *monster, list_node_t *node)
{
    destroy_character(rpg->engine, monster->character);
    list_remove_node(GAME(rpg)->monsters, node);
    monster->destroy(monster);
    free(monster);
}
