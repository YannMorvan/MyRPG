/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** list_get_node.c
*/

#include "list.h"

list_node_t *list_get_node(list_t *list, void *value)
{
    list_node_t *node;

    if (list == NULL)
        return NULL;
    for (node = list->head; node; node = node->next)
        if (node->value == value)
            return node;
    return NULL;
}
