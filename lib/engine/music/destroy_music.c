/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_music.c
*/

#include <malloc.h>

#include "engine/struct.h"

void destroy_music(engine_t *engine)
{
    sfMusic_destroy(engine->music->music);
    free(engine->music);
}
