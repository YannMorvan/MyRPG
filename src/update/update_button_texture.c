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

    if (button->state == CLICK)
        offset = sfTexture_getSize(
            button->character->sprite->texture->texture).x / 3;
    else if (button->state == HOVER)
        offset = sfTexture_getSize(
            button->character->sprite->texture->texture).x / 3 * 2;
    sfSprite_setTextureRect(button->character->sprite->sprite,
        (sfIntRect){(int)offset, 0, 16, 16});
}