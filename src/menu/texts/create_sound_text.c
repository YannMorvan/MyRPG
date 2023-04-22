/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_sound_text.c
*/

#include "my_rpg/menu.h"

sfBool create_sound_text(rpg_t *rpg)
{
    text_t *text = create_text(rpg->engine, "sound",
        "...................................", (sfVector2f){0, 0});

    if (!text)
        return sfFalse;
    update_sound_text(rpg, (button_t *)rpg->engine->buttons->tail->value);
    return sfTrue;
}
