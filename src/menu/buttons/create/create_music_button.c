/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_music_button.c
*/

#include "ice/macro.h"
#include "my_rpg/menu.h"

static void update_left_button(void *component, button_t *button)
{
    rpg_t *rpg = (rpg_t *)component;

    update_button_texture(button);
    if (button->state == CLICK)
        set_volume_music(rpg->engine, rpg->engine->music->volume - 5);
    update_music_text(rpg, button);
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
    if (button->state == CLICK)
        set_volume_music(rpg->engine, rpg->engine->music->volume + 5);
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

button_t *create_music_button(rpg_t *rpg, float index, UNUSED int scene)
{
    if (!create_left_button(rpg, index)
        || !create_right_button(rpg, index))
        return NULL;
    return (create_music_text(rpg)) ? rpg->engine->buttons->tail->value : NULL;
}
