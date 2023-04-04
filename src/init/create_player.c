/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_player.c
*/

#include <stdlib.h>

#include "my_rpg.h"
#include "ice/memory.h"

player_t *create_player(engine_t *engine)
{
    player_t *player = ice_calloc(1, sizeof(player_t));

    if (!player)
        return NULL;
    player->speed = 150;
    player->character = create_character(engine, (sfVector2f){0, 0},
        "player", "./assets/player.png");
    if (!player->character)
        return NULL;
    sfSprite_setTextureRect(player->character->sprite->sprite,
        (sfIntRect){0, 0, 16, 21});
    sfSprite_setScale(player->character->sprite->sprite,
        (sfVector2f){2, 2});
    sfSprite_setOrigin(player->character->sprite->sprite,
        (sfVector2f){8, 10});
    return player;
}
