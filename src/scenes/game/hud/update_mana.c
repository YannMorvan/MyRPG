/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_mana.c
*/

#include "my_rpg/game.h"

hud_t *update_manafont(hud_t *hud)
{
    sfVector2f size = {hud->m_mana, 14};

    sfRectangleShape_setSize(hud->mana_font, size);
    return hud;
}

hud_t *update_mana(hud_t *hud)
{
    sfVector2f pos = {10, 65};
    sfVector2f size = {hud->c_mana, 10};
    sfColor sfmBlue = sfColor_fromRGBA(0, 0, 205, 255);

    hud = update_manafont(hud);
    sfRectangleShape_setPosition(hud->mana_bar, pos);
    sfRectangleShape_setSize(hud->mana_bar, size);
    sfRectangleShape_setFillColor(hud->mana_bar, sfmBlue);
    sfRectangleShape_setOutlineThickness(hud->mana_bar, 1.5);
    sfRectangleShape_setOutlineColor(hud->mana_bar, sfWhite);
    return hud;
}
