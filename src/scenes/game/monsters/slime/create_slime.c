/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_slime.c
*/

#include <malloc.h>

#include "ice/memory.h"
#include "my_rpg/game.h"
#include "ice/string.h"

static void update_slime(rpg_t *rpg, monster_t *monster, list_node_t *node)
{
    slime_t *slime = monster->component;

    move_delta_character(rpg->engine, monster->character, slime->speed);
    if (monster->character->collider->collide & COLLIDER_ATTACK)
        slime->health -= 25 * GAME(rpg)->player->stats->intel;
    if (monster->character->collider->collide & COLLIDER_PLAYER) {
        GAME(rpg)->player->stats->life -= 2;
        rpg->engine->hud->c_life = GAME(rpg)->player->stats->life;
        rpg->engine->hud = update_life(rpg->engine, rpg->engine->hud);
        GAME(rpg)->player->stats->life = rpg->engine->hud->c_life;
    }
    if (slime->health <= 0) {
        if (GAME(rpg)->quest->name != NULL &&
            ice_strcmp(GAME(rpg)->quest->name, "Kill") == 0)
            GAME(rpg)->quest->progress++;
        GAME(rpg)->player->stats->exp += 10;
        destroy_monster(rpg, monster, node);
    }
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
    slime->speed = (sfVector2f){0, 0};
    monster->character = create_character(rpg->engine, (sfVector2f){500, 200},
        "slime", "./assets/slime.png");
    if (!monster->character)
        return sfFalse;
    slime->health = 100;
    center_character(monster->character);
    monster->update = update_slime;
    monster->destroy = destroy_slime;
    collider_set_type(monster->character->collider, COLLIDER_MONSTER);
    return list_add(game->monsters, monster);
}
