/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** create_attacks.c
*/

#include <malloc.h>

#include "my_rpg/game.h"
#include "ice/memory.h"

sfBool create_attacks(rpg_t *rpg, game_t *game)
{
    game->attacks = list_create();
    if (!game->attacks)
        return sfFalse;
    if (!create_melee(rpg, game))
        return sfFalse;
    return sfTrue;
}