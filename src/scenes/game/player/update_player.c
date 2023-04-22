/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_player.c
*/

#include "my_rpg/game.h"
#include "ice/string.h"

void undo_velocity(player_t *player)
{
    float fspeed = (float)player->speed;

    if (player->velocity.x)
        player->velocity.x = (player->velocity.x > 0) ? -fspeed : fspeed;
    if (player->velocity.y)
        player->velocity.y = (player->velocity.y > 0) ? -fspeed : fspeed;
}

void update_player(rpg_t *rpg)
{
    player_t *player = GAME(rpg)->player;
    sfBool collide = player->character->collider->collide == COLLIDER_WALL;
    list_node_t *node = list_get_node(rpg->engine->sprites,
        GAME(rpg)->player->character->sprite);

    if (collide)
        undo_velocity(player);
    move_delta_character(rpg->engine, player->character, player->velocity);
    if (collide)
        player->velocity = (sfVector2f){0, 0};
    list_pop_node(rpg->engine->sprites, node);
    list_add_node(rpg->engine->sprites, node);
}
