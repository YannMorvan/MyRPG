/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** event_game.c
*/

#include "my_rpg/menu.h"
#include "my_rpg/game.h"

static void event_key_pressed(rpg_t *rpg)
{
    if (EVENT(rpg).key.code == sfKeyEscape) {
        if (GAME(rpg)->scene == GAME_MAP)
            GAME(rpg)->create_sub_scene = create_buttons_menu_game;
        if (GAME(rpg)->scene == GAME_MENU)
            GAME(rpg)->create_sub_scene = create_buttons_map_game;
        if (GAME(rpg)->scene == GAME_SETTINGS)
            GAME(rpg)->create_sub_scene = create_buttons_menu_game;
    }
}

void event_game(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(WINDOW(rpg), &EVENT(rpg))) {
        if (event_engine(rpg->engine, EVENT(rpg)))
            continue;
        if (GAME(rpg)->scene == GAME_MAP && event_player(rpg, EVENT(rpg)))
            continue;
        switch (EVENT(rpg).type) {
            case sfEvtKeyPressed: event_key_pressed(rpg); break;
            default: break;
        }
    }
}
