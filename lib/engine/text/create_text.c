/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_text.c
*/

#include "ice/memory.h"
#include "engine/struct.h"
#include "ice/string.h"

text_t *create_text(engine_t *engine, char *name, char *str, sfVector2f pos)
{
    text_t *text = ice_calloc(1, sizeof(text_t));

    if (!text)
        return NULL;
    text->text = sfText_create();
    text->name = ice_strdup(name);
    if (!text->text || !text->name)
        return NULL;
    sfText_setString(text->text, str);
    sfText_setPosition(text->text, pos);
    sfText_setFont(text->text, ((font_t *)engine->fonts->head->value)->font);
    return list_add(engine->texts, text) ? text : NULL;
}
