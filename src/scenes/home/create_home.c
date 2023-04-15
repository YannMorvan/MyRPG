/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_home.c
*/

#include "my_rpg/home.h"

sfBool create_home(rpg_t *rpg)
{
    return load_background(rpg) && load_icon(rpg) && create_buttons(rpg);
}
