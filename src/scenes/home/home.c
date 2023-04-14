/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** home.c
*/

#include "my_rpg/home.h"

sfBool home(void *component)
{
    rpg_t *rpg = (rpg_t *)component;

    if (!create_home(rpg))
        return sfFalse;
    while (scene_is_open(rpg->engine, home)) {
        event_home(rpg);
        update_home(rpg);
        display_home(rpg);
    }
    return destroy_home(rpg);
}
