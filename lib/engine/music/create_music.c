/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_music.c
*/

#include "ice/memory.h"
#include "engine/struct.h"

music_t *create_music(engine_t *engine, char *path)
{
    engine->music = ice_calloc(1, sizeof(music_t));

    if (!engine->music)
        return NULL;
    engine->music->music = sfMusic_createFromFile(path);
    engine->music->volume = 100;
    if (!engine->music->music)
        return NULL;
    sfMusic_setVolume(engine->music->music, engine->music->volume);
    sfMusic_setLoop(engine->music->music, sfTrue);
    sfMusic_play(engine->music->music);
    return engine->music;
}
