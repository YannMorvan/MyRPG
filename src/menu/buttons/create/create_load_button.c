/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_load_button.c
*/

#include "my_rpg.h"
#include "ice/macro.h"
#include "my_rpg/menu.h"

static void update_load_button(void *component, button_t *button)
{
    rpg_t *rpg = (rpg_t *)component;

    update_button_texture(button);
    if (button->state == CLICK)
        rpg->engine->scene = game;
}

button_t *create_load_button(rpg_t *rpg, float index, UNUSED int scene)
{
    button_t *button = create_button(rpg->engine, (sfVector2f){0, 0},
        "load", "./assets/buttons/load.png");

    if (!button || !set_button(rpg, button, index))
        return NULL;
    button->update = update_load_button;
    return button;
}
