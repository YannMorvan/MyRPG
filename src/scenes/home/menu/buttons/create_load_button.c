/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_load_button.c
*/

#include "my_rpg.h"

static void update_load_button(void *component, button_t *button)
{
    rpg_t *rpg = (rpg_t *)component;

    update_button_texture(button);
    if (button->state == CLICK)
        rpg->engine->scene = game;
}

button_t *create_load_button(rpg_t *rpg, float index)
{
    button_t *button = create_button(rpg->engine, (sfVector2f){0, 0},
        "load", "./assets/buttons/load.png");
    sfVector2u size;

    if (!button)
        return NULL;
    size = sfTexture_getSize(
        button->character->sprite->texture->texture);
    set_rect_character(button->character, (sfIntRect){0, 0,
        (int)size.x / 3, (int)size.y});
    center_character(button->character);
    scale_character(button->character, (sfVector2f){4, 4});
    button->update = &update_load_button;
    set_pos_character(button->character, (sfVector2f){
        (float)rpg->engine->window->mode.width / 2,
        (float)rpg->engine->window->mode.height / 2
        + (float)(index * 4 * (float)size.y)});
    return button;
}
