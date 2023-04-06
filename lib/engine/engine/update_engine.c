/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_engine.c
*/

#include "engine/mouse.h"
#include "engine/button.h"
#include "engine/collider.h"

void update_engine(engine_t *engine, void *component)
{
    sfTime elapsed_time = sfClock_restart(engine->time->clock);

    engine->time->delta = sfTime_asSeconds(elapsed_time);
    update_mouse(engine, engine->mouse);
    update_collision(engine);
    update_buttons(engine, component);
}
