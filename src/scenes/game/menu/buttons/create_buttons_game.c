/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_buttons_game.c
*/

#include "my_rpg/menu.h"
#include "my_rpg/game.h"
#include "my_rpg/home.h"

sfBool create_buttons_settings_game(rpg_t *rpg)
{
    button_t *(*array[])(rpg_t *rpg, float index) = {
        create_music_button,
        create_sound_button,
        create_size_button_game,
        create_exit_button_game,
        NULL
    };
    ssize_t size = sizeof(array) / sizeof(array[0]) - 2;

    GAME(rpg)->scene = GAME_SETTINGS;
    for (int i = 0; array[i]; i++)
        if (!array[i](rpg, (float)i - (float)size / 2))
            return sfFalse;
    return sfTrue;
}

sfBool create_buttons_menu_game(rpg_t *rpg)
{
    button_t *(*array[])(rpg_t *rpg, float index) = {
        create_load_button,
        create_options_button_game,
        create_exit_button_game,
        NULL
    };
    ssize_t size = sizeof(array) / sizeof(array[0]) - 2;

    GAME(rpg)->scene = GAME_MENU;
    for (int i = 0; array[i]; i++)
        if (!array[i](rpg, (float)i - (float)size / 2))
            return sfFalse;
    return sfTrue;
}

sfBool create_buttons_map_game(rpg_t *rpg)
{
    GAME(rpg)->scene = GAME_MAP;
    return !create_pause_button(rpg) ? sfFalse : sfTrue;
}
