/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** event_home.c
*/

#include "my_rpg/home.h"

static void event_key_pressed(rpg_t *rpg)
{
    if (EVENT(rpg).key.code == sfKeyEscape) {
        if (HOME(rpg)->scene == HOME_MENU)
            sfRenderWindow_close(rpg->engine->window->window);
        else
            HOME(rpg)->create_sub_scene = create_buttons_home;
    }
}

void event_home(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(WINDOW(rpg), &EVENT(rpg))) {
        if (event_engine(rpg->engine, EVENT(rpg)))
            continue;
        switch (EVENT(rpg).type) {
            case sfEvtKeyPressed: event_key_pressed(rpg); break;
            default: break;
        }
    }
}
