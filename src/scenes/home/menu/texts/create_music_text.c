/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_music_text.c
*/

#include "my_rpg/home.h"

sfBool create_music_text(rpg_t *rpg)
{
    text_t *text = create_text(rpg->engine, "music",
        "...................................", (sfVector2f){0, 0});

    if (!text)
        return sfFalse;
    update_music_text(rpg, (button_t *)rpg->engine->buttons->tail->value);
    return sfTrue;
}
