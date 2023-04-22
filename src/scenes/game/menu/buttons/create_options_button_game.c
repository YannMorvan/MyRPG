/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_options_button_game.c
*/

#include "my_rpg.h"
#include "my_rpg/menu.h"
#include "my_rpg/game.h"

static void update_options_button(void *component, button_t *button)
{
    rpg_t *rpg = (rpg_t *)component;

    update_button_texture(button);
    if (button->state == CLICK)
        GAME(rpg)->create_sub_scene = create_buttons_settings_game;
}

button_t *create_options_button_game(rpg_t *rpg, float index)
{
    button_t *button = create_button(rpg->engine, (sfVector2f){0, 0},
        "options", "./assets/buttons/options.png");

    if (!button || !set_button(rpg, button, index))
        return NULL;
    button->update = update_options_button;
    return button;
}
