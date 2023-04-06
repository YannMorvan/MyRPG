/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event_engine.c
*/

#include "engine/mouse.h"

void event_engine(engine_t *engine, sfEvent event)
{
    event_mouse(engine, event);
}
