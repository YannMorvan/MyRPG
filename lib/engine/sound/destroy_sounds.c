/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_sounds.c
*/

#include <malloc.h>

#include "engine/sound.h"

void destroy_sounds(engine_t *engine)
{
    list_destroy_node(engine->sounds->sounds, (void *)destroy_sound);
    free(engine->sounds);
}
