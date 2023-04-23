/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_sounds.c
*/

#include "ice/memory.h"
#include "engine/struct.h"

sounds_t *create_sounds(void)
{
    sounds_t *sounds = ice_calloc(1, sizeof(sounds_t));

    if (!sounds)
        return NULL;
    sounds->sounds = list_create();
    sounds->volume = 50;
    return (!sounds->sounds) ? NULL : sounds;
}
