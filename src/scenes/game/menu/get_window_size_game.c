/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** get_window_size_game.c
*/

#include "my_rpg/game.h"

sfVector2u get_window_size_game(rpg_t *rpg)
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

    if (GAME(rpg)->size_index < 0)
        GAME(rpg)->size_index = 0;
    if (GAME(rpg)->size_index >= size)
        GAME(rpg)->size_index = size - 1;
    return ratio[GAME(rpg)->size_index];
}
