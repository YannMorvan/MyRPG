/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_floor.c
*/

#include <stdlib.h>

#include "my_rpg/struct.h"

sfBool set_floor(rpg_t *rpg, int x, int y)
{
    sprite_t *sprite = add_sprite_and_texture(rpg->engine,
        "floor", "./assets/map/floor.png");

    if (!sprite)
        return sfFalse;
    sfSprite_setPosition(sprite->sprite,
        (sfVector2f){(float)x * 32 + 32, (float)y * 32 + 32});
    sfSprite_setScale(sprite->sprite, (sfVector2f){2, 2});
    sfSprite_setTextureRect(sprite->sprite,
        (sfIntRect){16 * (rand() % 3), 0, 16, 16});
    return sfTrue;
}
