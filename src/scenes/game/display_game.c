/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** display_game.c
*/

#include "my_rpg/struct.h"
#include "my_rpg/game.h"

void display_game(rpg_t *rpg)
{
    clear_window(rpg->engine);
    display_sprites(rpg->engine);
    display_texts(rpg->engine);
    display_hud(rpg->engine);
    sfRenderWindow_display(WINDOW(rpg));
}
