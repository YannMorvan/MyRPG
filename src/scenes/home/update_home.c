/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_home.c
*/

#include "my_rpg/struct.h"

void update_home(rpg_t *rpg)
{
    update_engine(rpg->engine, rpg);
    write_framerate(rpg->engine);
}
