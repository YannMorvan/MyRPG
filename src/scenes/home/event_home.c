/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event_home.c
*/

#include "my_rpg.h"

static void event_key_pressed(rpg_t *rpg)
{
    if (EVENT(rpg).key.code == sfKeyEscape)
        sfRenderWindow_close(WINDOW(rpg));
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
