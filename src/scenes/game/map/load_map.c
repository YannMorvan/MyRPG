/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** load_map.c
*/

#include <stdlib.h>

#include "my_rpg.h"
#include "ice/array.h"
#include "ice/macro.h"
#include "ice/string.h"
#include "my_rpg/game.h"

static char *get_map(void)
{
    char maps[][100] = {
        "./assets/config/maps/map1.txt",
        "./assets/config/maps/map2.txt",
        "./assets/config/maps/map3.txt",
        "./assets/config/maps/map4.txt",
        "./assets/config/maps/map5.txt",
    };
    int index = rand() % (sizeof(maps) / sizeof(maps[0]));

    return read_file(maps[index]);
}

static sfVector2i get_offset(rpg_t *rpg, char **lines)
{
    sfVector2i offset = {0, 0};

    for (; lines[offset.y]; offset.y++)
        offset.x = MAX(offset.x, (int)ice_strlen(lines[offset.y]));
    return (sfVector2i){
        (int)rpg->engine->window->mode.width / 64 - offset.x / 2,
        (int)rpg->engine->window->mode.height / 64 - offset.y / 2 + 1};
}

static sfBool set_tile(rpg_t *rpg, char **map, int y, sfVector2i offset)
{
    sfBool ret = sfTrue;

    for (int x = 0; map[y][x]; x++) {
        switch (map[y][x]) {
            case 'f':
                ret = set_floor(rpg, (sfVector2i){x, y}, offset); break;
            case 'w':
                ret = set_wall(rpg, map, (sfVector2i){x, y}, offset); break;
            case 'p':
                ret = set_player(rpg, (sfVector2i){x, y}, offset); break;
            case 'm':
                ret = set_monster(rpg, (sfVector2i){x, y}, offset); break;
            case 'l':
                ret = set_ladder(rpg, (sfVector2i){x, y}, offset); break;
            case 'n':
                ret = set_npc(rpg, (sfVector2i){x, y}, offset); break;
        }
        if (!ret)
            return sfFalse;
    }
    return ret;
}

sfBool load_map(rpg_t *rpg)
{
    char *file = get_map();
    sfVector2i center;
    char **lines;

    if (!file)
        return sfFalse;
    lines = ice_strsplit(file, "\n");
    if (!lines)
        return sfFalse;
    center = get_offset(rpg, lines);
    for (int y = 0; lines[y]; y++)
        if (!set_tile(rpg, lines, y, center))
            return sfFalse;
    ice_free_array((void **)lines);
    free(file);
    return sfTrue;
}
