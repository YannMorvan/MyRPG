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
    sfBool (*monster[])(rpg_t *rpg, game_t *game) = {
        create_slime,
        NULL
    };
    int r = rand() % (int)(sizeof(monster) / sizeof(monster[0]) - 1);

    return monster[r](rpg, GAME(rpg));
}

sfBool set_npc(rpg_t *rpg, sfVector2i pos, sfVector2i offset)
{
    sfVector2f fpos = get_tile_pos(pos, offset);
    monster_t *monster;
    sfIntRect rect;

    if (!set_floor(rpg, pos, offset) || !create_npc(rpg))
        return sfFalse;
    monster = (monster_t *)GAME(rpg)->monsters->tail->value;
    rect = sfSprite_getTextureRect(monster->character->sprite->sprite);
    fpos.x += (float)rect.width;
    fpos.y += (float)rect.height;
    set_pos_character(monster->character, fpos);
    return sfTrue;
}
