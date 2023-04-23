/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_life.c
*/

#include "my_rpg/game.h"

hud_t *update_life(engine_t *engine, hud_t *hud)
{
    unsigned int life = hud->m_life;

    hud->m_life = 0;
    if (hud->c_life > life)
        hud->c_life = life;
    if (hud->c_life > 1)
        for (; hud->m_life <= hud->c_life - 2;)
            hud = init_heart(engine, hud, 1);
    if (hud->c_life - hud->m_life == 1)
        hud = init_heart(engine, hud, 2);
    for (; hud->m_life < life;)
        hud = init_heart(engine, hud, 3);
    return hud;
}
