/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_volume_music.c
*/

#include "engine/struct.h"

void set_volume_music(engine_t *engine, float volume)
{
    if (volume < 0 || volume > 100)
        return;
    engine->music->volume = volume;
    sfMusic_setVolume(engine->music->music, volume);
}
