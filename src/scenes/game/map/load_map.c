/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** load_map.c
*/

#include <malloc.h>
#include <stdlib.h>

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

static sfBool set_floor(rpg_t *rpg, sfVector2i pos, sfVector2i offset)
{
    sprite_t *floor = add_sprite_and_texture(rpg->engine,
        "floor", "./assets/map/floor.png");
    sfIntRect rect = {0, 0, 16, 16};
    int r = rand() % 100;

    if (!floor)
        return sfFalse;
    if (r > 70)
        rect.left = (r > 85) ? 16 : 32;
    sfSprite_setPosition(floor->sprite, get_tile_pos(pos, offset));
    sfSprite_setTextureRect(floor->sprite, rect);
    sfSprite_setScale(floor->sprite, (sfVector2f){2, 2});
    return sfTrue;
}

static sfBool set_player(rpg_t *rpg, sfVector2i pos, sfVector2i offset)
{
    sfVector2f fpos = get_tile_pos(pos, offset);
    sfIntRect rect;

    if (GAME(rpg)->player)
        return sfFalse;
    GAME(rpg)->player = create_player(rpg->engine);
    if (!GAME(rpg)->player)
        return sfFalse;
    rect = sfSprite_getTextureRect(
        GAME(rpg)->player->character->sprite->sprite);
    fpos.x += (float)rect.width;
    fpos.y += (float)rect.height / 2;
    set_pos_character(GAME(rpg)->player->character, fpos);
    return set_floor(rpg, pos, offset);
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
        }
        if (!ret)
            return sfFalse;
    }
    return ret;
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
