/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_player.c
*/

#include "my_rpg/game.h"

sfBool set_player(rpg_t *rpg, sfVector2i pos, sfVector2i offset)
{
    sfVector2f fpos = get_tile_pos(pos, offset);
    sfIntRect rect;

    rect = sfSprite_getTextureRect(
        GAME(rpg)->player->character->sprite->sprite);
    fpos.x += (float)rect.width;
    fpos.y += (float)rect.height / 2;
    set_pos_character(GAME(rpg)->player->character, fpos);
    return set_floor(rpg, pos, offset);
}
