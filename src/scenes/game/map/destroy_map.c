/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_map.c
*/

#include <malloc.h>

#include "my_rpg/game.h"

void destroy_map(rpg_t *rpg)
{
    clear_map(rpg);
    list_destroy(GAME(rpg)->map->floors);
    list_destroy(GAME(rpg)->map->walls);
    free(GAME(rpg)->map);
}
