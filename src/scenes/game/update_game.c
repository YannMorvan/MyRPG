/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_game.c
*/

#include "my_rpg/game.h"

void update_game(rpg_t *rpg)
{
    update_engine(rpg->engine, rpg);
    update_player(rpg);
    update_monsters(rpg);
    write_framerate(rpg->engine);
}
