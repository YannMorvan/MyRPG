/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_ladder.c
*/

#include "my_rpg/game.h"

sfBool set_ladder(rpg_t *rpg, sfVector2i pos, sfVector2i offset)
{
    character_t *ladder = create_character(rpg->engine,
        get_tile_pos(pos, offset), "ladder", "./assets/map/ladder.png");

    if (!ladder)
        return sfFalse;
    set_scale_character(ladder, (sfVector2f){2, 2});
    collider_set_type(ladder->collider, COLLIDER_LADDER);
    return list_add(GAME(rpg)->map->walls, ladder);
}
