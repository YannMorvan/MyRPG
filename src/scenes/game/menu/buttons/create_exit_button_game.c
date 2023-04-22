/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_exit_button_game.c
*/

#include "my_rpg.h"
#include "my_rpg/menu.h"
#include "my_rpg/game.h"

static void update_exit_button(void *component, button_t *button)
{
    rpg_t *rpg = (rpg_t *)component;

    update_button_texture(button);
    if (button->state != CLICK)
        return;
    if (GAME(rpg)->scene == GAME_MENU)
        rpg->engine->scene = home;
    else if (GAME(rpg)->scene == GAME_SETTINGS)
        GAME(rpg)->create_sub_scene = create_buttons_menu_game;
}

button_t *create_exit_button_game(rpg_t *rpg, float index)
{
    button_t *button = create_button(rpg->engine, (sfVector2f){0, 0},
        "exit", "./assets/buttons/exit.png");

    if (!button || !set_button(rpg, button, index))
        return NULL;
    button->update = update_exit_button;
    return button;
}
