/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_size_button.c
*/

#include "my_rpg.h"
#include "my_rpg/home.h"

static void update_left_button(void *component, button_t *button)
{
    rpg_t *rpg = (rpg_t *)component;

    update_button_texture(button);
    if (button->state == CLICK && HOME(rpg)->size_index > 0) {
        HOME(rpg)->size_index--;
        sfRenderWindow_setSize(rpg->engine->window->window,
            get_window_size(rpg));
    }
    update_size_text(rpg, button);
}

static button_t *create_left_button(rpg_t *rpg, float index)
{
    button_t *button = create_button(rpg->engine, (sfVector2f){0, 0},
        "left", "./assets/buttons/left.png");

    if (!button || !set_button(rpg, button, index))
        return NULL;
    button->update = update_left_button;
    move_character(button->character, (sfVector2f){-250, 0});
    return button;
}

static void update_right_button(void *component, button_t *button)
{
    rpg_t *rpg = (rpg_t *)component;

    update_button_texture(button);
    if (button->state == CLICK) {
        HOME(rpg)->size_index++;
        sfRenderWindow_setSize(rpg->engine->window->window,
            get_window_size(rpg));
    }
}

static button_t *create_right_button(rpg_t *rpg, float index)
{
    button_t *button = create_button(rpg->engine, (sfVector2f){0, 0},
        "right", "./assets/buttons/right.png");

    if (!button || !set_button(rpg, button, index))
        return NULL;
    button->update = update_right_button;
    move_character(button->character, (sfVector2f){250, 0});
    return button;
}

button_t *create_size_button(rpg_t *rpg, float index)
{
    if (!create_left_button(rpg, index)
        || !create_right_button(rpg, index))
        return NULL;
    return (create_size_text(rpg)) ? rpg->engine->buttons->tail->value : NULL;
}
