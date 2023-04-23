/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_sound.c
*/

#include <malloc.h>

#include "engine/struct.h"

void destroy_sound(sound_t *sound)
{
    sfSound_destroy(sound->sound);
    sfSoundBuffer_destroy(sound->buffer);
    free(sound->name);
    free(sound);
}
