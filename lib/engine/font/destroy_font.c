/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_font.c
*/

#include <malloc.h>

#include "engine/struct.h"

void destroy_font(font_t *font)
{
    sfFont_destroy(font->font);
    free(font);
}
