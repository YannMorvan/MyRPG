/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** destroy_home.c
*/

#include <malloc.h>

#include "my_rpg/home.h"

sfBool destroy_home(rpg_t *rpg)
{
    free(HOME(rpg));
    return destroy_scene(rpg->engine);
}
