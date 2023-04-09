/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_slime.c
*/

#include <malloc.h>

#include "ice/memory.h"
#include "my_rpg/game.h"

static void update_slime(rpg_t *rpg, monster_t *monster, list_node_t *node)
{
    slime_t *slime = monster->component;

    move_character(rpg->engine, monster->character, slime->speed);
    if (monster->character->collider->collide & COLLIDER_PLAYER)
        destroy_monster(rpg, monster, node);
}

static void destroy_slime(monster_t *monster)
{
    free(monster->component);
}

sfBool create_slime(rpg_t *rpg, game_t *game)
{
    monster_t *monster = ice_calloc(1, sizeof(monster_t));
    slime_t *slime = ice_calloc(1, sizeof(slime_t));

    if (!monster || !slime)
        return sfFalse;
    monster->component = slime;
    slime->speed = (sfVector2f){100, 100};
    monster->character = create_character(rpg->engine, (sfVector2f){0, 0},
        "slime", "./assets/slime.png");
    if (!monster->character)
        return sfFalse;
    center_character(monster->character);
    monster->update = update_slime;
    monster->destroy = destroy_slime;
    collider_set_type(monster->character->collider, COLLIDER_MONSTER);
    return !list_add(game->monsters, monster);
}
