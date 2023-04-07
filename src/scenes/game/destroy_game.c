/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_game.c
*/

#include <malloc.h>

#include "my_rpg/game.h"

sfBool destroy_game(rpg_t *rpg)
{
    destroy_player(GAME(rpg)->player);
    list_destroy(GAME(rpg)->monsters);
    free(GAME(rpg));
    return destroy_scene(rpg->engine);
}