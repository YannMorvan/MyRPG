/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** destroy_rpg.c
*/

#include <stdlib.h>

#include "my_rpg.h"

void destroy_rpg(rpg_t *rpg)
{
    destroy_engine(rpg->engine);
    free(rpg);
}
