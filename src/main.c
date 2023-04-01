/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main.c
*/

#include <time.h>
#include <stdlib.h>

#include <malloc.h>

#include "my_rpg.h"

int main(void)
{
    game_t *game = malloc(sizeof(game_t));

    srand(time(NULL));
    if (!game)
        return 84;
    game->engine = create_engine(960, 540, "My Rpg", sfClose | sfResize);
    if (!game->engine)
        return 84;
    for (int i = 0; i < 100; i++)
        if (!create_character(game->engine,
            (sfVector2f){(float)(rand() % 960), (float)(rand() % 540)},
            "character", "./assets/slime.png"))
            return 84;

    while (sfRenderWindow_isOpen(game->engine->window->window)) {
        while (sfRenderWindow_pollEvent(game->engine->window->window, &game->engine->event)) {
            if (game->engine->event.type == sfEvtClosed)
                sfRenderWindow_close(game->engine->window->window);
        }
        game->engine->time->delta = sfClock_restart(game->engine->time->clock);

        write_framerate(game->engine);
//        sfRenderWindow_clear(game->engine->window->window, sfBlack);
        clear_window(game->engine);
        display_sprites(game->engine);
        update_collision(game->engine);
        display_quadtree(game->engine);
        display_collision(game->engine);
        sfRenderWindow_display(game->engine->window->window);
    }

    return 0;
}
