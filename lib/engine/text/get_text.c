/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** get_text.c
*/

#include "ice/string.h"
#include "engine/struct.h"

text_t *get_text(engine_t *engine, char *name)
{
    text_t *text;

    for (list_node_t *node = engine->texts->head; node; node = node->next) {
        text = node->value;
        if (!ice_strcmp(text->name, name))
            return text;
    }
    return NULL;
}
