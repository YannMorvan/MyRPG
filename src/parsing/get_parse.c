/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** get_parse.c
*/

#include "ice/string.h"
#include "my_rpg/struct.h"

static parse_t *get_parse(list_t *list, char *name)
{
    for (list_node_t *node = list->head; node; node = node->next) {
        if (!ice_strcmp(((parse_t *)node->value)->name, name))
            return node->value;
    }
    return NULL;
}

long long get_parse_value(list_t *list, char *name)
{
    parse_t *parse = get_parse(list, name);

    if (!parse)
        return 0;
    return parse->value;
}

char *get_parse_string(list_t *list, char *name)
{
    parse_t *parse = get_parse(list, name);

    if (!parse)
        return NULL;
    return ice_strdup(parse->string);
}
