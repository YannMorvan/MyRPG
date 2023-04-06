/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** get_game.c
*/

#include <time.h>
#include <stdlib.h>

#include "my_rpg.h"

game_t *create_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->engine = create_engine(960, 540, "My Rpg", sfDefaultStyle);
    if (!game->engine)
        return NULL;
    srand(time(NULL));
    game->player = create_player(game->engine);
    if (!game->player)
        return NULL;
    game->monsters = list_create();
    if (!game->monsters)
        return NULL;
    sfRenderWindow_setFramerateLimit(WINDOW(game), 60);
    if (!create_pause_button(game))
        return NULL;
    return game;
}
