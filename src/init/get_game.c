/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** get_game.c
*/

#include <time.h>
#include <stdlib.h>

#include "my_rpg.h"

game_t *get_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->engine = create_engine(960, 540, "My Rpg", sfDefaultStyle);
    if (!game->engine)
        return NULL;
    srand(time(NULL));
    return game;
}
