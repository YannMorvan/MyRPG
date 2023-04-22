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
    destroy_map(rpg);
    destroy_monsters(rpg);
    destroy_npcs(rpg);
    free(GAME(rpg)->quest);
    free(GAME(rpg)->attacks);
    free(GAME(rpg));
    return destroy_scene(rpg->engine);
}
