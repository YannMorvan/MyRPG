/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** event_game.c
*/

#include "my_rpg.h"
#include "my_rpg/game.h"

static void event_key_pressed(rpg_t *rpg)
{
    if (EVENT(rpg).key.code == sfKeyEscape)
        rpg->engine->scene = home;
}

void event_game(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(WINDOW(rpg), &EVENT(rpg))) {
        if (event_engine(rpg->engine, EVENT(rpg)))
            continue;
        if (event_player(rpg, EVENT(rpg)))
            continue;
        switch (EVENT(rpg).type) {
            case sfEvtKeyPressed: event_key_pressed(rpg); break;
            default: break;
        }
    }
}
