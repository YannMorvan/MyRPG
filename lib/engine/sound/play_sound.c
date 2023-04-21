/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** play_sound.c
*/

#include "engine/sound.h"

void play_sound(engine_t *engine, char *name)
{
    sound_t *sound = get_sound(engine, name);

    if (!sound)
        return;
    sfSound_setVolume(sound->sound, engine->sounds->volume);
    sfSound_play(sound->sound);
}
