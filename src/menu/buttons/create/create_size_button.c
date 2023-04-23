/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_size_button.c
*/

#include "my_rpg/home.h"
#include "my_rpg/menu.h"

static button_t *create_left_button(rpg_t *rpg, float index, int scene)
{
    button_t *button = create_button(rpg->engine, (sfVector2f){0, 0},
        "left", "./assets/buttons/left.png");

    if (!button || !set_button(rpg, button, index))
        return NULL;
    button->update = (scene == HOME_ID) ?
        update_left_button_home : update_left_button_game;
    move_character(button->character, (sfVector2f){-250, 0});
    return button;
}

static button_t *create_right_button(rpg_t *rpg, float index, int scene)
{
    button_t *button = create_button(rpg->engine, (sfVector2f){0, 0},
        "right", "./assets/buttons/right.png");

    if (!button || !set_button(rpg, button, index))
        return NULL;
    button->update = (scene == HOME_ID) ?
        update_right_button_home : update_right_button_game;
    move_character(button->character, (sfVector2f){250, 0});
    return button;
}

button_t *create_size_button(rpg_t *rpg, float index, int scene)
{
    if (!create_left_button(rpg, index, scene)
        || !create_right_button(rpg, index, scene))
        return NULL;
    return (create_size_text(rpg)) ? rpg->engine->buttons->tail->value : NULL;
}
