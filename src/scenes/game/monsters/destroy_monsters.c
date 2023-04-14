/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** destroy_monsters.c
*/

#include <malloc.h>

#include "my_rpg/game.h"

static void destroy_monster_struct(monster_t *monster)
{
    monster->destroy(monster);
    free(monster);
}

void destroy_monsters(rpg_t *rpg)
{
    list_destroy_node(GAME(rpg)->monsters, (void *)destroy_monster_struct);
}
