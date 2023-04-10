/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_wall.c
*/

#include <malloc.h>

#include "ice/string.h"
#include "my_rpg/game.h"

static sfBool set_upper_wall(rpg_t *rpg, sfVector2i pos, sfVector2i offset)
{
    sprite_t *wall = add_sprite_and_texture(rpg->engine,
        "wall", "./assets/map/wall.png");

    if (!wall)
        return sfFalse;
    sfSprite_setPosition(wall->sprite, get_tile_pos(pos, offset));
    sfSprite_setTextureRect(wall->sprite, (sfIntRect){16, 0, 16, 16});
    sfSprite_setScale(wall->sprite, (sfVector2f){2, 2});
    return sfTrue;
}

static sfBool set_right_wall(rpg_t *rpg, sfVector2i pos, sfVector2i offset)
{
    sprite_t *wall = add_sprite_and_texture(rpg->engine,
        "wall", "./assets/map/wall.png");

    if (!wall)
        return sfFalse;
    sfSprite_setPosition(wall->sprite, get_tile_pos(pos, offset));
    sfSprite_setTextureRect(wall->sprite, (sfIntRect){0, 112, 16, 16});
    sfSprite_setScale(wall->sprite, (sfVector2f){2, 2});
    return sfTrue;
}

static sfBool set_left_wall(rpg_t *rpg, sfVector2i pos, sfVector2i offset)
{
    sprite_t *wall = add_sprite_and_texture(rpg->engine,
        "wall", "./assets/map/wall.png");

    if (!wall)
        return sfFalse;
    sfSprite_setPosition(wall->sprite, get_tile_pos(pos, offset));
    sfSprite_setTextureRect(wall->sprite, (sfIntRect){16, 112, 16, 16});
    sfSprite_setScale(wall->sprite, (sfVector2f){2, 2});
    return sfTrue;
}

sfBool set_wall(rpg_t *rpg, char **map, sfVector2i pos, sfVector2i offset)
{
    character_t *wall = create_character(rpg->engine,
        get_tile_pos(pos, offset), "wall", "./assets/map/wall.png");

    if (!wall)
        return sfFalse;
    scale_character(wall, (sfVector2f){2, 2});
    set_rect_character(wall, (sfIntRect){16, 16, 16, 16});
    collider_set_type(wall->collider, COLLIDER_WALL);
    free(wall);
    return !(((pos.y < 1 || (pos.x < (int)ice_strlen(map[pos.y - 1])
        && map[pos.y - 1][pos.x] != 'w'))
        && !set_upper_wall(rpg, (sfVector2i){pos.x, pos.y - 1}, offset))
        || (pos.x > 1 && map[pos.y][pos.x - 1] == 'f'
        && !set_left_wall(rpg, (sfVector2i){pos.x, pos.y}, offset))
        || (pos.x < (int)ice_strlen(map[pos.y])
        && map[pos.y][pos.x + 1] == 'f'
        && !set_right_wall(rpg, (sfVector2i){pos.x, pos.y}, offset)));
}
