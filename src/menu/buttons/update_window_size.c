/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_window_size.c
*/

#include "my_rpg/menu.h"
#include "my_rpg/home.h"
#include "my_rpg/game.h"

static sfVector2u update_window_size_home(rpg_t *rpg, sfVector2u ratio[],
    int size)
{
    if (HOME(rpg)->size_index < 0)
        HOME(rpg)->size_index = 0;
    if (HOME(rpg)->size_index >= size)
        HOME(rpg)->size_index = size - 1;
    return ratio[HOME(rpg)->size_index];
}

static sfVector2u update_window_size_game(rpg_t *rpg, sfVector2u ratio[],
    int size)
{
    if (GAME(rpg)->size_index < 0)
        GAME(rpg)->size_index = 0;
    if (GAME(rpg)->size_index >= size)
        GAME(rpg)->size_index = size - 1;
    return ratio[GAME(rpg)->size_index];
}

void update_window_size(rpg_t *rpg, int scene)
{
    sfVector2u ratio[] = {
        {640, 360},
        {960, 540},
        {1280, 720},
        {1920, 1080},
        {2560, 1440},
        {3840, 2160},
    };
    int size = sizeof(ratio) / sizeof(ratio[0]);
    sfVector2u window_size = (scene == HOME_ID) ?
        update_window_size_home(rpg, ratio, size) :
        update_window_size_game(rpg, ratio, size);

    sfRenderWindow_setSize(rpg->engine->window->window, window_size);
}
