/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_engine.c
*/

#include "engine/mouse.h"

void update_engine(engine_t *engine)
{
    sfTime elapsed_time = sfClock_restart(engine->time->clock);

    engine->time->delta = sfTime_asSeconds(elapsed_time);
    update_mouse(engine, engine->mouse);
}
