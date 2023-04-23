/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** display_hud.c
*/

#include "my_rpg/game.h"

void display_spell(rpg_t *rpg, unsigned int i)
{
    sfRenderWindow *win = rpg->engine->window->window;
    hud_t *hud = rpg->engine->hud;

    if (GAME(rpg)->player->stats->cd[i] > 0.0)
        sfRenderWindow_drawSprite(win, hud->spell[i + 3]->sprite, NULL);
    else
        sfRenderWindow_drawSprite(win, hud->spell[i]->sprite, NULL);
}

void display_hud(rpg_t *rpg)
{
    sfRenderWindow *win = rpg->engine->window->window;
    hud_t *hud = rpg->engine->hud;

    for (unsigned int i = 0; i < (hud->m_life / 2); i++)
        sfRenderWindow_drawSprite(win, hud->heart->sprite, NULL);
    for (unsigned int i = 0; i < 3; i++) {
        sfRenderWindow_drawSprite(win, hud->inv->sprite, NULL);
        if (hud->spell[i])
            display_spell(rpg, i);
    }
    sfRenderWindow_drawRectangleShape(win, hud->mana_font, NULL);
    sfRenderWindow_drawRectangleShape(win, hud->mana_bar, NULL);
}
