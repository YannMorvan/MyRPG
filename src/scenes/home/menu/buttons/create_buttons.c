/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_buttons.c
*/

#include "ice/macro.h"
#include "my_rpg/home.h"

sfBool create_buttons(rpg_t *rpg)
{
    button_t *(*array[])(rpg_t *rpg, float index) = {
        create_new_button,
        create_start_button,
        create_options_button,
        create_exit_button,
        NULL
    };
    ssize_t size = sizeof(array) / sizeof(array[0]) - 2;

    for (int i = 0; array[i]; i++)
        if (!array[i](rpg, (float)i - (float)size / 2))
            return sfFalse;
    return sfTrue;
}
