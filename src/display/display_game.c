/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_game.c
*/

#include "my_rpg.h"

void display_game(game_t *game)
{
    clear_window(game->engine);
    display_sprites(game->engine);
    sfRenderWindow_display(WINDOW(game));
}
