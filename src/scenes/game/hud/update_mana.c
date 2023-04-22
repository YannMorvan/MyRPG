/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_mana.c
*/

#include "my_rpg/game.h"

hud_t *update_mana(hud_t *hud)
{
    sfVector2f pos = {0, 0};
    sfVector2f size = {2, hud->c_mana};
    sfColor sfmBlue = sfColor_fromRGBA(0, 0, 205, 255);

    sfRectangleShape_setPosition(hud->mana[1]->bar, pos);
    sfRectangleShape_setSize(hud->mana[1]->bar, size);
    sfRectangleShape_setFillColor(hud->mana[1]->bar, sfmBlue);
    sfRectangleShape_setOutlineThickness(hud->mana[1]->bar, 2.0);
    sfRectangleShape_setOutlineColor(hud->mana[1]->bar, sfWhite);
    return hud;
}
