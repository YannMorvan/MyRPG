/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_mouse.c
*/

#include <malloc.h>

#include "engine/struct.h"

void destroy_mouse(mouse_t *mouse)
{
    free(mouse);
}
