/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** event_player.c
*/

#include "my_rpg/game.h"

static sfBool player_actions(rpg_t *rpg, sfEvent event)
{
    if (event.key.code == sfKeySpace)
        return create_spell(rpg, GAME(rpg));
    if (event.key.code == sfKeyE)
        GAME(rpg)->player->interact = sfTrue;
    return false;
}

static sfBool key_pressed(rpg_t *rpg, sfEvent event)
{
    float speed = (float)GAME(rpg)->player->speed;
    sfVector2f *velocity = &GAME(rpg)->player->velocity;

    if (event.key.code == sfKeyLeft || event.key.code == sfKeyQ)
        velocity->x = -speed;
    if (event.key.code == sfKeyRight || event.key.code == sfKeyD)
        velocity->x = speed;
    if (event.key.code == sfKeyUp || event.key.code == sfKeyZ)
        velocity->y = -speed;
    if (event.key.code == sfKeyDown || event.key.code == sfKeyS)
        velocity->y = speed;
    return player_actions(rpg, event);
}

static sfBool key_unpressed(rpg_t *rpg, sfEvent event)
{
    sfVector2f *velocity = &GAME(rpg)->player->velocity;

    if (event.key.code == sfKeyLeft || event.key.code == sfKeyQ
        || event.key.code == sfKeyRight || event.key.code == sfKeyD)
        velocity->x = 0;
    if (event.key.code == sfKeyUp || event.key.code == sfKeyZ
        || event.key.code == sfKeyDown || event.key.code == sfKeyS)
        velocity->y = 0;
    if (event.key.code == sfKeyE)
        GAME(rpg)->player->interact = sfFalse;
    return false;
}

sfBool event_player(rpg_t *rpg, sfEvent event)
{
    if (event.type == sfEvtKeyPressed)
        return key_pressed(rpg, event);
    if (event.type == sfEvtKeyReleased)
        return key_unpressed(rpg, event);
    return false;
}
