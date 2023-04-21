/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_text.c
*/

#include <malloc.h>

#include "engine/struct.h"

void destroy_text(text_t *text)
{
    sfText_destroy(text->text);
    free(text->name);
    free(text);
}
