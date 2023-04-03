/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event_player.c
*/

#include "my_rpg.h"

void event_player(game_t *game, sfEvent event)
{
    float speed = (float)game->player->speed;

    if (event.type == sfEvtKeyPressed)
        switch (event.key.code) {
            case sfKeyLeft: game->player->velocity.x = -speed; break;
            case sfKeyRight: game->player->velocity.x = speed; break;
            case sfKeyUp: game->player->velocity.y = -speed; break;
            case sfKeyDown: game->player->velocity.y = speed; break;
            default: return;
        }
    if (event.type == sfEvtKeyReleased)
        switch (event.key.code) {
            case sfKeyLeft: game->player->velocity.x = 0; break;
            case sfKeyRight: game->player->velocity.x = 0; break;
            case sfKeyUp: game->player->velocity.y = 0; break;
            case sfKeyDown: game->player->velocity.y = 0; break;
            default: return;
        }
}
