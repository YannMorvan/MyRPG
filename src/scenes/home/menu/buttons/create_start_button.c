/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_start_button.c
*/

#include "my_rpg.h"
#include "ice/macro.h"
#include "my_rpg/menu.h"
#include "my_rpg/home.h"

static void update_start_button(void *component, button_t *button)
{
    rpg_t *rpg = (rpg_t *)component;

    update_button_texture(button);
    if (button->state == CLICK)
        rpg->engine->scene = tutorial;
}

button_t *create_start_button(rpg_t *rpg, float index, UNUSED int scene)
{
    button_t *button = create_button(rpg->engine, (sfVector2f){0, 0},
        "start", "./assets/buttons/start.png");

    if (!button || !set_button(rpg, button, index))
        return NULL;
    button->update = update_start_button;
    return button;
}
