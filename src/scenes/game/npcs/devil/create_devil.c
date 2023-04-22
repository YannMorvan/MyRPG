/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** create_devil.c
*/

#include <malloc.h>
#include <stdlib.h>

#include "ice/memory.h"
#include "my_rpg/game.h"

static void get_quest(rpg_t *rpg)
{
    int random = rand() % 2;

    if (random == 0) {
        GAME(rpg)->quest->name = "Kill";
        GAME(rpg)->quest->description = "Kill 10 enemies";
        GAME(rpg)->quest->progress = 0;
        GAME(rpg)->quest->reward = 100;
        GAME(rpg)->quest->objective = 10;
    } else {
        GAME(rpg)->quest->name = "Survive";
        GAME(rpg)->quest->description = "Survive The next 2 stages";
        GAME(rpg)->quest->progress = 0;
        GAME(rpg)->quest->reward = 100;
        GAME(rpg)->quest->objective = 3;
    }
}

static void update_devil(rpg_t *rpg, npc_t *npc)
{
    if (npc->character->collider->collide & COLLIDER_PLAYER &&
        GAME(rpg)->player->interact == sfTrue &&
        GAME(rpg)->quest->name == NULL) {
        GAME(rpg)->player->interact = sfFalse;
        get_quest(rpg);
        }
}

static void destroy_devil(npc_t *npc)
{
    free(npc->component);
}

sfBool create_devil(rpg_t *rpg, game_t *game)
{
    npc_t *npc = ice_calloc(1, sizeof(npc_t));

    if (!npc)
        return sfFalse;
    npc->character = create_character(rpg->engine, (sfVector2f){500, 200},
        "npc", "./assets/characters/devil.png");
    if (!npc->character)
        return sfFalse;
    center_character(npc->character);
    set_scale_character(npc->character, (sfVector2f){2, 2});
    npc->update = update_devil;
    npc->destroy = destroy_devil;
    collider_set_type(npc->character->collider, COLLIDER_NPC);
    return list_add(game->npcs, npc);
}
