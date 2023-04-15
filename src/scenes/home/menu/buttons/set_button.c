/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_button.c
*/

#include "my_rpg.h"

sfBool set_button(rpg_t *rpg, button_t *button, float index)
{
    sfVector2u size = sfTexture_getSize(
        button->character->sprite->texture->texture);
    set_rect_character(button->character, (sfIntRect){0, 0,
        (int)size.x / 3, (int)size.y});
    scale_character(button->character, (sfVector2f){4, 4});
    center_character(button->character);
    set_pos_character(button->character, (sfVector2f){
        (float)rpg->engine->window->mode.width / 2,
        (float)rpg->engine->window->mode.height / 1.65f
            + (float)(index * 4 * (float)size.y)});
    return sfTrue;
}
