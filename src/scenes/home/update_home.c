/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_home.c
*/

#include "my_rpg/menu.h"
#include "my_rpg/home.h"

void update_home(rpg_t *rpg)
{
    update_engine(rpg->engine, rpg);
    if (HOME(rpg)->create_sub_scene) {
        clear_sub_scene(rpg);
        HOME(rpg)->create_sub_scene(rpg);
        HOME(rpg)->create_sub_scene = NULL;
    }
}
