/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** destroy_parse.c
*/

#include <malloc.h>

#include "my_rpg/struct.h"

static void destroy_parse_struct(parse_t *parse)
{
    free(parse->name);
    if (parse->string)
        free(parse->string);
    free(parse);
}

void destroy_parse(list_t *list)
{
    list_destroy_node(list, (void *)destroy_parse_struct);
}
