/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_size_text.c
*/

#include "my_rpg/home.h"

sfBool create_size_text(rpg_t *rpg)
{
    text_t *text = create_text(rpg->engine, "size",
        "...................................", (sfVector2f){0, 0});

    if (!text)
        return sfFalse;
    update_size_text(rpg, (button_t *)rpg->engine->buttons->tail->value);
    return sfTrue;
}
