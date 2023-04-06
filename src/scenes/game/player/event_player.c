/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event_player.c
*/

#include "my_rpg/game.h"

sfBool event_player(rpg_t *rpg, sfEvent event)
{
    float speed = (float)GAME(rpg)->player->speed;
    sfVector2f *velocity = &GAME(rpg)->player->velocity;

    if (event.type == sfEvtKeyPressed)
        switch (event.key.code) {
            case sfKeyLeft: velocity->x = -speed; return true;
            case sfKeyRight: velocity->x = speed; return true;
            case sfKeyUp: velocity->y = -speed; return true;
            case sfKeyDown: velocity->y = speed; return true;
            default: return false;
        }
    if (event.type == sfEvtKeyReleased)
        switch (event.key.code) {
            case sfKeyLeft: velocity->x = 0; return true;
            case sfKeyRight: velocity->x = 0; return true;
            case sfKeyUp: velocity->y = 0; return true;
            case sfKeyDown: velocity->y = 0; return true;
            default: return false;
        }
    return false;
}
