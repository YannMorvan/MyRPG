/*
** EPITECH PROJECT, 2023
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
    update_attacks(rpg);
    write_framerate(rpg->engine);
}
