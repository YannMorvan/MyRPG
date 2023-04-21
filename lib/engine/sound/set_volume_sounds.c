/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_volume_sounds.c
*/

#include "engine/struct.h"

void set_volume_sounds(engine_t *engine, float volume)
{
    if (volume < 0 || volume > 100)
        return;
    engine->sounds->volume = volume;
}
