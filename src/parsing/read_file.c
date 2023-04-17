/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** read_file.c
*/

#include <malloc.h>
#include <sys/stat.h>

#include "my_rpg/struct.h"

char *read_file(char *path)
{
    FILE *file = fopen(path, "r");
    struct stat st;
    char *buffer = NULL;

    if (!file)
        return NULL;
    if (stat(path, &st) == -1)
        return NULL;
    buffer = malloc(sizeof(char) * st.st_size + 1);
    if (!buffer)
        return NULL;
    if (fread(buffer, st.st_size, sizeof(char), file) == (ul_t)st.st_size)
        return NULL;
    buffer[st.st_size] = '\0';
    fclose(file);
    return buffer;
}
