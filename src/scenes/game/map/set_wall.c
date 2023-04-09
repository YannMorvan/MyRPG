/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_wall.c
*/

#include <malloc.h>

#include "ice/string.h"
#include "my_rpg/game.h"

sfBool create_roof(rpg_t *rpg, sfVector2f pos, sfIntRect rect)
{
    sprite_t *sprite = add_sprite(rpg->engine, "wall");

    if (!sprite)
        return sfFalse;
    pos.y -= 32;
    rect.top -= 16;
    sfSprite_setPosition(sprite->sprite, pos);
    sfSprite_setScale(sprite->sprite, (sfVector2f){2, 2});
    sfSprite_setTextureRect(sprite->sprite, rect);
    return sfTrue;
}

sfBool create_wall(rpg_t *rpg, sfVector2f pos, sfIntRect rect, sfBool as_roof)
{
    character_t *character = create_character(rpg->engine, pos,
        "wall", "./assets/map/wall.png");

    if (!character)
        return sfFalse;
    scale_character(character, (sfVector2f){2, 2});
    set_rect_character(character, rect);
    collider_set_type(character->collider, COLLIDER_WALL);
    free(character);
    return as_roof ? create_roof(rpg, pos, rect) : sfTrue;
}

sfBool set_wall(rpg_t *rpg, char **map, int x, int y)
{
    sfVector2f pos = (sfVector2f){(float)x * 32 + 32, (float)y * 32 + 32};
    sfIntRect rect = (sfIntRect){16, 16, 16, 16};
    sfBool as_roof = (y == 0 || ice_strlen(map[y - 1]) < (ull_t)x
            || map[y - 1][x] != 'w');

    return create_wall(rpg, pos, rect, as_roof);
}
