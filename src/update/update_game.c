/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_game.c
*/

#include "my_rpg.h"

void update_game(game_t *game)
{
    update_engine(game->engine, game);
    update_player(game);
    update_monsters(game);
    update_collision(game->engine);
    write_framerate(game->engine);
}
