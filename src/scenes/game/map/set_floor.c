/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_floor.c
*/

#include <stdlib.h>

#include "my_rpg/game.h"

sfBool set_floor(rpg_t *rpg, sfVector2i pos, sfVector2i offset)
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
