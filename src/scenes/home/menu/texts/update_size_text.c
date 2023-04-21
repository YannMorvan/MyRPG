/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_size_text.c
*/

#include "ice/printf.h"
#include "my_rpg/home.h"

void update_size_text(rpg_t *rpg, button_t *button)
{
    text_t *text = get_text(rpg->engine, "size");
    sfVector2u size = sfRenderWindow_getSize(WINDOW(rpg));
    sfFloatRect rect = sfText_getGlobalBounds(text->text);
    sfVector2f pos;
    char str[36];

    ice_sprintf(str, "Window size: %ux%u", size.x, size.y);
    pos = sfSprite_getPosition(button->character->sprite->sprite);
    sfText_setPosition(text->text,
        (sfVector2f){pos.x + 250 - rect.width / 2, pos.y - rect.height});
    sfText_setString(text->text, str);
}
