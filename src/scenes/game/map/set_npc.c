/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_npc.c
*/

#include <stdlib.h>

#include "my_rpg/game.h"

static sfBool create_npc(rpg_t *rpg)
{
    sfBool (*npc[])(rpg_t *rpg, game_t *game) = {
        create_devil,
        NULL
    };
    int r = rand() % (int)(sizeof(npc) / sizeof(npc[0]) - 1);

    return npc[r](rpg, GAME(rpg));
}

sfBool set_npc(rpg_t *rpg, sfVector2i pos, sfVector2i offset)
{
    sfVector2f fpos = get_tile_pos(pos, offset);
    npc_t *npc;
    sfIntRect rect;

    if (!set_floor(rpg, pos, offset) || !create_npc(rpg))
        return sfFalse;
    npc = (npc_t *)GAME(rpg)->npcs->tail->value;
    rect = sfSprite_getTextureRect(npc->character->sprite->sprite);
    fpos.x += (float)rect.width;
    fpos.y += (float)rect.height;
    set_pos_character(npc->character, fpos);
    return sfTrue;
}
