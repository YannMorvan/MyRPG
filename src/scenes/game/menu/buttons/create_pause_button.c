/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_pause_button.c
*/

#include "my_rpg/menu.h"
#include "my_rpg/game.h"

static void update_pause_button(void *component, button_t *button)
{
    rpg_t *rpg = (rpg_t *)component;

    update_button_texture(button);
    if (button->state == CLICK)
        GAME(rpg)->create_sub_scene = create_buttons_menu_game;
}

button_t *create_pause_button(rpg_t *rpg)
{
    button_t *button = create_button(rpg->engine, (sfVector2f){0, 0},
        "pause", "./assets/buttons/pause.png");

    if (!button)
        return NULL;
    set_scale_character(button->character, (sfVector2f){2, 2});
    button->update = update_pause_button;
    return button;
}
