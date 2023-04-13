/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** destroy_attack.c
*/

#include <malloc.h>

#include "my_rpg/game.h"

void destroy_attack(rpg_t *rpg, attack_t *attack, list_node_t *node)
{
    destroy_character(rpg->engine, attack->character);
    list_remove_node(GAME(rpg)->attacks, node);
    attack->destroy(attack);
    free(attack);
}
