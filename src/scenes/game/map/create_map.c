/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_map.c
*/

#include <malloc.h>

#include "my_rpg/game.h"

map_t *create_map(rpg_t *rpg)
{
    map_t *map = malloc(sizeof(map_t));

    if (!map)
        return NULL;
    map->floors = list_create();
    map->walls = list_create();
    if (!map->floors || !map->walls)
        return NULL;
    GAME(rpg)->map = map;
    if (!load_map(rpg))
        return NULL;
    return map;
}
