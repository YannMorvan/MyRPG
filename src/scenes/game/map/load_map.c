/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** load_map.c
*/

#include <malloc.h>

#include "my_rpg.h"
#include "ice/array.h"
#include "ice/string.h"
#include "my_rpg/game.h"

static sfBool parse_char(rpg_t *rpg, char **lines, int y)
{
    for (int x = 0; lines[y][x]; x++) {
        if ((lines[y][x] == 'w' && !set_wall(rpg, lines, x, y))
            || (lines[y][x] == 'f' && !set_floor(rpg, x, y)))
            return sfFalse;
    }
    return sfTrue;
}

sfBool load_map(rpg_t *rpg)
{
    char *file = read_file("./map.txt");
    char **lines;

    if (!file)
        return sfFalse;
    lines = ice_strsplit(file, "\n");
    if (!lines)
        return sfFalse;
    for (int y = 0; lines[y]; y++)
        if (!parse_char(rpg, lines, y))
            return sfFalse;
    ice_free_array((void **)lines);
    free(file);
    return sfTrue;
}
