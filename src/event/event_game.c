/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event_game.c
*/

#include "my_rpg.h"

static void event_key_pressed(game_t *game)
{
    if (EVENT(game).key.code == sfKeyEscape)
        sfRenderWindow_close(WINDOW(game));
}

void event_game(game_t *game)
{
    while (sfRenderWindow_pollEvent(WINDOW(game), &EVENT(game))) {
        event_player(game, EVENT(game));
        switch (EVENT(game).type) {
            case sfEvtClosed: sfRenderWindow_close(WINDOW(game)); break;
            case sfEvtKeyPressed: event_key_pressed(game); break;
            default: break;
        }
    }
}
