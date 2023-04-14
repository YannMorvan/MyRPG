/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** load_map.c
*/

#include <malloc.h>

#include "my_rpg.h"
#include "ice/array.h"
#include "ice/macro.h"
#include "ice/string.h"
#include "my_rpg/game.h"

static sfVector2i get_offset(rpg_t *rpg, char **lines)
{
    sfVector2i offset = {0, 0};

    for (; lines[offset.y]; offset.y++)
        offset.x = MAX(offset.x, (int)ice_strlen(lines[offset.y]));
    return (sfVector2i){
        (int)rpg->engine->window->mode.width / 64 - offset.x / 2,
        (int)rpg->engine->window->mode.height / 64 - offset.y / 2};
}

static sfBool set_floor(rpg_t *rpg,sfVector2i pos, sfVector2i offset)
{
    sprite_t *floor = add_sprite_and_texture(rpg->engine,
        "floor", "./assets/map/floor.png");

    if (!floor)
        return sfFalse;
    sfSprite_setPosition(floor->sprite, get_tile_pos(pos, offset));
    sfSprite_setTextureRect(floor->sprite, (sfIntRect){0, 0, 16, 16});
    sfSprite_setScale(floor->sprite, (sfVector2f){2, 2});
    return sfTrue;
}

static sfBool set_tile(rpg_t *rpg, char **map, int y, sfVector2i offset)
{

    for (int x = 0; map[y][x]; x++) {
        if ((map[y][x] == 'f'
            && !set_floor(rpg, (sfVector2i){x, y}, offset))
            || (map[y][x] == 'w'
            && !set_wall(rpg, map, (sfVector2i){x, y}, offset)))
            return sfFalse;
    }
    return sfTrue;
}

sfBool load_map(rpg_t *rpg)
{
    char *file = read_file("./assets/config/maps/map.txt");
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
