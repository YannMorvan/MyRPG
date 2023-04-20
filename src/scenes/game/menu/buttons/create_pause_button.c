/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_pause_button.c
*/

#include "my_rpg.h"
#include "ice/macro.h"

static void update_pause_button(UNUSED void *component, button_t *button)
{
    update_button_texture(button);
}

button_t *create_pause_button(rpg_t *rpg)
{
    button_t *button = create_button(rpg->engine, (sfVector2f){0, 0},
        "pause", "./assets/buttons/pause.png");

    if (!button)
        return NULL;
    set_scale_character(button->character, (sfVector2f){2, 2});
    button->update = &update_pause_button;
    return button;
}
