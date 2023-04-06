/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_button.c
*/

#include <malloc.h>

#include "engine/struct.h"

void destroy_button(button_t *button)
{
    free(button->character);
    free(button);
}
