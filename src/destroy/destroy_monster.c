/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_monster.c
*/

#include <malloc.h>

#include "my_rpg.h"

void destroy_monster(monster_t *monster)
{
    free(monster->character);
    free(monster);
}
