/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** file_parse.c
*/

#include <malloc.h>
#include <sys/stat.h>

#include "my_rpg.h"
#include "ice/int.h"
#include "ice/array.h"
#include "ice/string.h"
#include "ice/memory.h"

static bool parser_set_variable(parse_t *parse, char *variable)
{
    char *c;
    ull_t len = ice_strlen(variable);

    if (variable[0] == '\"' && variable[len - 1] == '\"') {
        parse->string = ice_strndup(variable + 1, len - 2);
        if (!parse->string)
            return false;
    } else {
        parse->value = ice_strtol(variable, &c);
        if (*c != '\0')
            return false;
    }
    return true;
}

static bool parser_add_variable(list_t *list, char *line)
{
    parse_t *parse = ice_calloc(1, sizeof(parse_t));
    char **split = ice_strsplit(line, "=");

    if (!split || ice_array_len((void *)split) != 2)
        return false;
    parse->name = ice_strdup(split[0]);
    if (!parse->name)
        return false;
    if (!parser_set_variable(parse, split[1]))
        return false;
    ice_free_array((void **)split);
    return !list_add(list, parse);
}

list_t *parse_file(char *path)
{
    char *file = read_file(path);
    char **lines;
    list_t *list = list_create();

    if (!file || !list)
        return NULL;
    lines = ice_strsplit(file, "\n");
    if (!lines)
        return NULL;
    for (int i = 0; lines[i]; i++) {
        if (lines[i][0] == '#' || lines[i][0] == '\0')
            continue;
        if (!parser_add_variable(list, lines[i]))
            return NULL;
    }
    ice_free_array((void **)lines);
    free(file);
    return list;
}
