/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** destroy_hud.c
*/

#include <malloc.h>

#include "my_rpg/game.h"

void destroy_hud(hud_t *hud)
{
    sfRectangleShape_destroy(hud->mana_font);
    sfRectangleShape_destroy(hud->mana_bar);
    free(hud);
}
