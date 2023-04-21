/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** get_sound.c
*/

#include "ice/string.h"
#include "engine/struct.h"

sound_t *get_sound(engine_t *engine, char *name)
{
    sound_t *sound;

    for (list_node_t *node = engine->sounds->sounds->head; node;
        node = node->next) {
        sound = node->value;
        if (!ice_strcmp(sound->name, name))
            return sound;
    }
    return NULL;
}
