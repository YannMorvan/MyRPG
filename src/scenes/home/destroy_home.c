/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_home.c
*/

#include "my_rpg/struct.h"

sfBool destroy_home(rpg_t *rpg)
{
    return destroy_scene(rpg->engine);
}
