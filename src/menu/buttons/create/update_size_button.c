/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_size_button.c
*/

#include "my_rpg/menu.h"
#include "my_rpg/home.h"
#include "my_rpg/game.h"

void update_right_button_home(void *component, button_t *button)
{
    rpg_t *rpg = (rpg_t *)component;

    update_button_texture(button);
    if (button->state == CLICK) {
        HOME(rpg)->size_index++;
        update_window_size(rpg, HOME_ID);
    }
}

void update_left_button_home(void *component, button_t *button)
{
    rpg_t *rpg = (rpg_t *)component;

    update_button_texture(button);
    if (button->state == CLICK) {
        HOME(rpg)->size_index--;
        update_window_size(rpg, HOME_ID);
    }
    update_size_text(rpg, button);
}

void update_left_button_game(void *component, button_t *button)
{
    rpg_t *rpg = (rpg_t *)component;

    update_button_texture(button);
    if (button->state == CLICK) {
        GAME(rpg)->size_index--;
        update_window_size(rpg, GAME_ID);
    }
    update_size_text(rpg, button);
}

void update_right_button_game(void *component, button_t *button)
{
    rpg_t *rpg = (rpg_t *)component;

    update_button_texture(button);
    if (button->state == CLICK) {
        GAME(rpg)->size_index++;
        update_window_size(rpg, GAME_ID);
    }
}
