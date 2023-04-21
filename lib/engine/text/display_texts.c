/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_texts.c
*/

#include "engine/struct.h"

void display_texts(engine_t *engine)
{
    for (list_node_t *node = engine->texts->head; node; node = node->next) {
        text_t *text = node->value;
        sfRenderWindow_drawText(engine->window->window, text->text, NULL);
    }
}
