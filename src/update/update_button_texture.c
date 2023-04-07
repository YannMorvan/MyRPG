/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_button_texture.c
*/

#include "my_rpg.h"

void update_button_texture(button_t *button)
{
    ui_t offset = 0;
    sfVector2u size = sfTexture_getSize(
        button->character->sprite->texture->texture);
    size.x /= 3;

    if (button->state == CLICK)
        offset = size.x;
    else if (button->state == HOVER)
        offset = size.x * 2;
    set_rect_character(button->character, (sfIntRect){(int)offset, 0,
        (int)size.x, (int)size.y});
}
