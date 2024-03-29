/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_save_button.c
*/

#include "ice/macro.h"
#include "my_rpg/menu.h"
#include "my_rpg/game.h"

static void update_save_button(void *component, button_t *button)
{
    rpg_t *rpg = (rpg_t *)component;

    update_button_texture(button);
    if (button->state == CLICK)
        save_game(rpg);
}

button_t *create_save_button(rpg_t *rpg , float index, UNUSED int scene)
{
    button_t *button = create_button(rpg->engine, (sfVector2f){0, 0},
        "save", "./assets/buttons/save.png");

    if (!button || !set_button(rpg, button, index))
        return NULL;
    button->update = update_save_button;
    return button;
}
