/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_game.c
*/

#include "my_rpg/game.h"

sfBool update_game(rpg_t *rpg)
{
    update_engine(rpg->engine, rpg);
    update_player(rpg);
    update_monsters(rpg);
    update_attacks(rpg);
    write_framerate(rpg->engine);

    if (GAME(rpg)->monsters->size == 0) {
        clear_map(rpg);
        return load_map(rpg);
    }
    return sfTrue;
}
