/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main.c
*/

#include <stdlib.h>

#include "my_rpg.h"

int main(void)
{
    game_t *game = create_game();

    if (!game)
        return 84;
    for (int i = 0; i < 10; i++)
        if (!add_monster(game))
            return 84;

    while (sfRenderWindow_isOpen(game->engine->window->window)) {
        while (sfRenderWindow_pollEvent(game->engine->window->window, &game->engine->event)) {
            if (game->engine->event.type == sfEvtClosed)
                sfRenderWindow_close(game->engine->window->window);
            event_player(game, game->engine->event);
        }
        sfTime elapsed_time = sfClock_restart(game->engine->time->clock);
        game->engine->time->delta = sfTime_asSeconds(elapsed_time);

        update_player(game);
        update_monsters(game);
        update_collision(game->engine);

        write_framerate(game->engine);
        clear_window(game->engine);
        display_sprites(game->engine);
        sfRenderWindow_display(game->engine->window->window);
    }

    return 0;
}
