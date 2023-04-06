/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_home.c
*/

#include "my_rpg/home.h"

sfBool create_home(rpg_t *rpg)
{
    return create_start_button(rpg) != NULL;
}
