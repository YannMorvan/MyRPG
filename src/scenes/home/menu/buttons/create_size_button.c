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
    sfVector2u ratio[] = {
        {640, 360},
        {960, 540},
        {1280, 720},
        {1920, 1080},
        {2560, 1440},
        {3840, 2160}
    };

    update_button_texture(button);
    if (button->state == CLICK && HOME(rpg)->size_index > 0) {
        HOME(rpg)->size_index--;
        sfRenderWindow_setSize(rpg->engine->window->window,
            ratio[HOME(rpg)->size_index]);
    }
}

static button_t *create_left_button(rpg_t *rpg, float index)
{
    button_t *button = create_button(rpg->engine, (sfVector2f){0, 0},
        "left", "./assets/buttons/left.png");

    if (!button || !set_button(rpg, button, index))
        return NULL;
    button->update = update_left_button;
    set_pos_character(button->character, (sfVector2f){-150, 0});
    return button;
}

static void update_right_button(void *component, button_t *button)
{
    rpg_t *rpg = (rpg_t *)component;
    sfVector2u ratio[] = {
        {640, 360},
        {960, 540},
        {1280, 720},
        {1920, 1080},
        {2560, 1440},
        {3840, 2160}
    };
    int size = sizeof(ratio) / sizeof(ratio[0]);

    update_button_texture(button);
    if (button->state == CLICK) {
        if (HOME(rpg)->size_index < size - 1) {
            HOME(rpg)->size_index++;
            sfRenderWindow_setSize(rpg->engine->window->window,
                ratio[HOME(rpg)->size_index]);
        }
    }
}

static button_t *create_right_button(rpg_t *rpg, float index)
{
    button_t *button = create_button(rpg->engine, (sfVector2f){0, 0},
        "right", "./assets/buttons/right.png");

    if (!button || !set_button(rpg, button, index))
        return NULL;
    button->update = update_right_button;
    set_pos_character(button->character, (sfVector2f){150, 0});
    return button;
}

button_t *create_size_button(rpg_t *rpg, float index)
{
    return (create_left_button(rpg, index)) ?
        create_right_button(rpg, index) : NULL;
}
