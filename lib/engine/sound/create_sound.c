/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_sound.c
*/

#include "ice/string.h"
#include "ice/memory.h"
#include "engine/struct.h"

sound_t *create_sound(engine_t *engine, char *name, char *path)
{
    sound_t *sound = ice_calloc(1, sizeof(sound_t));

    if (!sound)
        return NULL;
    sound->name = ice_strdup(name);
    sound->sound = sfSound_create();
    sound->buffer = sfSoundBuffer_createFromFile(path);
    if (!sound->name || !sound->sound || !sound->buffer)
        return NULL;
    sfSound_setBuffer(sound->sound, sound->buffer);
    sfSound_setVolume(sound->sound, engine->sounds->volume);
    return (list_add(engine->sounds->sounds, sound)) ? sound : NULL;
}
