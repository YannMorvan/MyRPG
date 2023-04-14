/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** destroy_game.c
*/

#include <malloc.h>

#include "my_rpg/game.h"

sfBool destroy_game(rpg_t *rpg)
{
    destroy_player(GAME(rpg)->player);
    destroy_monsters(rpg);
    free(GAME(rpg));
    return destroy_scene(rpg->engine);
}
