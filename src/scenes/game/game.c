/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** game.c
*/

#include "my_rpg/game.h"

sfBool game(void *component)
{
    rpg_t *rpg = (rpg_t *)component;

    rpg->scene = create_game(rpg);
    if (!rpg->scene)
        return sfFalse;
    while (scene_is_open(rpg->engine, game)) {
        event_game(rpg);
        update_game(rpg);
        display_game(rpg);
    }
    return destroy_game(rpg);
}
