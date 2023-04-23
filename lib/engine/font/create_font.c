/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_font.c
*/

#include "ice/memory.h"
#include "engine/struct.h"

font_t *create_font(engine_t *engine, char *path)
{
    font_t *font = ice_calloc(1, sizeof(font_t));

    if (!font)
        return (NULL);
    font->font = sfFont_createFromFile(path);
    return list_add(engine->fonts, font) ? font : NULL;
}
