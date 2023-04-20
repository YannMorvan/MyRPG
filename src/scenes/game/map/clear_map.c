/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** clear_map.c
*/

#include "my_rpg/game.h"

static void remove_floor(rpg_t *rpg, sprite_t *sprite)
{
    list_remove_node(GAME(rpg)->map->floors, sprite->node);
    destroy_sprite(sprite);
}

void clear_map(rpg_t *rpg)
{
    list_node_t *next;

    for (list_node_t *node = GAME(rpg)->map->floors->head; node; node = next) {
        next = node->next;
        remove_floor(rpg, node->value);
        list_remove_node(GAME(rpg)->map->floors, node);
    }
    for (list_node_t *node = GAME(rpg)->map->walls->head; node; node = next) {
        next = node->next;
        destroy_character(rpg->engine, node->value);
        list_remove_node(GAME(rpg)->map->walls, node);
    }
    for (list_node_t *node = GAME(rpg)->attacks->head; node; node = next) {
        next = node->next;
        destroy_attack(rpg, node->value, node);
    }
}
