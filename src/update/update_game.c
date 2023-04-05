/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_game.c
*/

#include "my_rpg.h"

void update_game(game_t *game)
{
    sfTime elapsed_time = sfClock_restart(game->engine->time->clock);
    game->engine->time->delta = sfTime_asSeconds(elapsed_time);
    update_player(game);
    update_monsters(game);
    update_collision(game->engine);
    write_framerate(game->engine);
}
