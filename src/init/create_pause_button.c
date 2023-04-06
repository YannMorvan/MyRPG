/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_pause_button.c
*/

#include "my_rpg.h"
#include "ice/macro.h"

static void update_pause_button(UNUSED void *component, button_t *button)
{
    int offset = 0;

    if (button->state == CLICK)
        offset = 16;
    else if (button->state == HOVER)
        offset = 32;
    sfSprite_setTextureRect(button->character->sprite->sprite,
        (sfIntRect){offset, 0, 16, 16});
}

button_t *create_pause_button(game_t *game)
{
    button_t *button = create_button(game->engine, (sfVector2f){0, 0},
        "pause", "./assets/buttons/pause.png");
    if (!button)
        return NULL;
    scale_character(button->character, (sfVector2f){2, 2});
    button->update = &update_pause_button;
    return button;
}
