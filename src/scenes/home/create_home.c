/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_home.c
*/

#include "ice/memory.h"
#include "my_rpg/home.h"

sfBool create_home(rpg_t *rpg)
{
    rpg->scene = ice_calloc(1, sizeof(home_t));

    return load_background(rpg) && load_icon(rpg) && create_buttons_home(rpg);
}
