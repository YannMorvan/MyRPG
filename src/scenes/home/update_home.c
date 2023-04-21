/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_home.c
*/

#include <malloc.h>

#include "my_rpg/home.h"

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

void update_home(rpg_t *rpg)
{
    update_engine(rpg->engine, rpg);
    write_framerate(rpg->engine);

    if (HOME(rpg)->create_sub_scene) {
        remove_buttons(rpg);
        remove_texts(rpg);
        HOME(rpg)->create_sub_scene(rpg);
        HOME(rpg)->create_sub_scene = NULL;
    }
}
