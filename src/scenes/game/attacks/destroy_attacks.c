/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** destroy_attacks.c
*/

#include <malloc.h>

#include "my_rpg/game.h"

static void destroy_attack_struct(attack_t *attack)
{
    attack->destroy(attack);
    free(attack);
}

void destroy_attacks(rpg_t *rpg)
{
    list_destroy_node(GAME(rpg)->attacks, (void *)destroy_attack_struct);
}
