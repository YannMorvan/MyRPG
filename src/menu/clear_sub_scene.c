/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** clear_sub_scene.c
*/

#include <malloc.h>

#include "my_rpg.h"

static void remove_buttons(rpg_t *rpg)
{
    list_node_t *node = rpg->engine->buttons->head;
    list_node_t *next;

    for (; node; node = next) {
        next = node->next;
        destroy_character(rpg->engine, ((button_t *)node->value)->character);
        free(node->value);
        free(node);
    }
    rpg->engine->buttons->head = NULL;
    rpg->engine->buttons->tail = NULL;
    rpg->engine->buttons->size = 0;
}

static void remove_texts(rpg_t *rpg)
{
    list_node_t *node = rpg->engine->texts->head;
    list_node_t *next;

    for (; node; node = next) {
        next = node->next;
        destroy_text(node->value);
        free(node);
    }
    rpg->engine->texts->head = NULL;
    rpg->engine->texts->tail = NULL;
    rpg->engine->texts->size = 0;
}

void clear_sub_scene(rpg_t *rpg)
{
    remove_buttons(rpg);
    remove_texts(rpg);
}
