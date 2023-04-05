/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"
#include "ice/macro.h"

int my_rpg(void)
{
    game_t *game = create_game();

    if (!game)
        return 84;
    for (int i = 0; i < 10; i++)
        if (!add_monster(game))
            return 84;
    while (sfRenderWindow_isOpen(WINDOW(game))) {
        event_game(game);
        update_game(game);
        display_game(game);
    }
    return 0;
}

int main(int ac, UNUSED char **av)
{
    if (ac != 1)
        return 84;
    return my_rpg();
}
