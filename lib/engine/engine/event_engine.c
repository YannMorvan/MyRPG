/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event_engine.c
*/

#include "engine/mouse.h"

sfBool event_engine(engine_t *engine, sfEvent event)
{
    if (event_mouse(engine, event))
        return true;
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(engine->window->window);
        return true;
    }
    return false;
}
