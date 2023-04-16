/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_exit_button.c
*/

#include "my_rpg.h"
#include "my_rpg/home.h"

static void update_exit_button(void *component, button_t *button)
{
    rpg_t *rpg = (rpg_t *)component;

    update_button_texture(button);
    if (button->state != CLICK)
        return;
    if (HOME(rpg)->scene == HOME_MENU)
        sfRenderWindow_close(rpg->engine->window->window);
    else
        HOME(rpg)->create_sub_scene = create_buttons_home;
}

button_t *create_exit_button(rpg_t *rpg, float index)
{
    button_t *button = create_button(rpg->engine, (sfVector2f){0, 0},
        "exit", "./assets/buttons/exit.png");

    if (!button || !set_button(rpg, button, index))
        return NULL;
    button->update = &update_exit_button;
    return button;
}
