/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_music_text.c
*/

#include "ice/printf.h"
#include "my_rpg/menu.h"

void update_music_text(rpg_t *rpg, button_t *button)
{
    text_t *text = get_text(rpg->engine, "music");
    sfFloatRect rect = sfText_getGlobalBounds(text->text);
    sfVector2f pos;
    char str[36];

    ice_sprintf(str, "Music volume: %.0f%%", rpg->engine->music->volume);
    pos = sfSprite_getPosition(button->character->sprite->sprite);
    sfText_setPosition(text->text,
        (sfVector2f){pos.x + 250 - rect.width / 2, pos.y - rect.height});
    sfText_setString(text->text, str);
}
