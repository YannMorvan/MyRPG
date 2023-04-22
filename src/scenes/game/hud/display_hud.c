/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** display_hud.c
*/

#include "my_rpg/game.h"

void display_hud(engine_t *engine)
{
    sfRenderWindow *win = engine->window->window;
    hud_t *hud = engine->hud;

    for (unsigned int i = 0; i < (hud->m_life / 2); i++)
        sfRenderWindow_drawSprite(win, hud->heart->sprite, NULL);
    for (unsigned int i = 0; i < 3; i++) {
        sfRenderWindow_drawSprite(win, hud->inv->sprite, NULL);
        sfRenderWindow_drawSprite(win, hud->spell[i]->sprite, NULL);
    }
}
