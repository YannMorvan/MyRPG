/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_player.c
*/

#include "my_rpg/game.h"
#include "ice/memory.h"

static void player_stats(player_t *player)
{
    player->stats = ice_calloc(1, sizeof(stats_t));
    player->stats->speed = 150;
    player->stats->intel = 1;
    player->stats->level = 1;
    player->stats->exp = 0;
    player->stats->mana = 100;
    player->stats->elapsed_time = 0;
    player->stats->wait_time = 1;
}

player_t *create_player(engine_t *engine)
{
    player_t *player = ice_calloc(1, sizeof(player_t));
    sfVector2f pos = {(float)engine->window->mode.width / 2,
        (float)engine->window->mode.height / 2};

    if (!player)
        return NULL;
    player_stats(player);
    player->character = create_character(engine, pos,
        "player", "./assets/player.png");
    if (!player->character)
        return NULL;
    set_rect_character(player->character, (sfIntRect){0, 0, 16, 21});
    scale_character(player->character, (sfVector2f){2, 2});
    center_character(player->character);
    collider_set_type(player->character->collider, COLLIDER_PLAYER);
    return player;
}
