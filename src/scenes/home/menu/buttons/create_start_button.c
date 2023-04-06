/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_play_button.c
*/

#include "my_rpg.h"

static void update_start_button(void *component, button_t *button)
{
    rpg_t *rpg = (rpg_t *)component;

    update_button_texture(button);
    if (button->state == CLICK)
        rpg->engine->scene = game;
}

button_t *create_start_button(rpg_t *rpg)
{
    button_t *button = create_button(rpg->engine, (sfVector2f){0, 0},
        "start", "./assets/buttons/start.png");
    if (!button)
        return NULL;
    scale_character(button->character, (sfVector2f){2, 2});
    button->update = &update_start_button;
    return button;
}
