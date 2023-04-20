/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_player.c
*/

#include "my_rpg/game.h"

<<<<<<< HEAD
static void update_player_stats(player_t *player, rpg_t *rpg)
{
    if (player->stats->exp >= 100) {
        player->stats->level += 1;
        player->stats->intel += 1;
        player->stats->exp = 0;
    }
    if (player->stats->mana < 100 &&
        player->stats->elapsed_time >= player->stats->wait_time)
        player->stats->mana += 10;
    if (player->stats->elapsed_time >= player->stats->wait_time)
        player->stats->elapsed_time -= player->stats->wait_time;
    if (player->stats->cd[0] > 0)
        player->stats->cd[0] -= rpg->engine->time->delta;
    if (player->stats->cd[1] > 0)
        player->stats->cd[1] -= rpg->engine->time->delta;
    if (player->stats->cd[2] > 0)
        player->stats->cd[2] -= rpg->engine->time->delta;
=======
void undo_velocity(player_t *player)
{
    float fspeed = (float)player->speed;

    if (player->velocity.x)
        player->velocity.x = (player->velocity.x > 0) ? -fspeed : fspeed;
    if (player->velocity.y)
        player->velocity.y = (player->velocity.y > 0) ? -fspeed : fspeed;
>>>>>>> 1e7e917561e8d0655e539f0a9a3c4249a1d82b9c
}

void update_player(rpg_t *rpg)
{
    player_t *player = GAME(rpg)->player;
    sfBool collide = player->character->collider->collide == COLLIDER_WALL;
    list_node_t *node = list_get_node(rpg->engine->sprites,
        GAME(rpg)->player->character->sprite);

<<<<<<< HEAD
    player->stats->elapsed_time += rpg->engine->time->delta;
    update_player_stats(player, rpg);
    move_character(rpg->engine, player->character, player->velocity);
    if (node) {
        list_pop_node(rpg->engine->sprites, node);
        list_add_node(rpg->engine->sprites, node);
    }
=======
    if (collide)
        undo_velocity(player);
    move_delta_character(rpg->engine, player->character, player->velocity);
    if (collide)
        player->velocity = (sfVector2f){0, 0};
    list_pop_node(rpg->engine->sprites, node);
    list_add_node(rpg->engine->sprites, node);
>>>>>>> 1e7e917561e8d0655e539f0a9a3c4249a1d82b9c
}
