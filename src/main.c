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
    game_t *game = get_game();
    list_t *characters = list_create();
    character_t *character = NULL;
    sfVector2f pos;

    if (!game || !characters)
        return 84;
    for (int i = 0; i < 100; i++) {
        character = create_character(game->engine,
            (sfVector2f) {(float) (rand() % 960), (float) (rand() % 540)},
            "character", "./assets/slime.png");
        if (!character)
            return 84;
        if (list_add(characters, character))
            return 84;
    }

    sfImage *icon = sfImage_createFromFile("./assets/slime.png");
    sfVector2u size = sfImage_getSize(icon);
    sfRenderWindow_setIcon(game->engine->window->window, size.x, size.y, sfImage_getPixelsPtr(icon));

    while (sfRenderWindow_isOpen(game->engine->window->window)) {
        while (sfRenderWindow_pollEvent(game->engine->window->window, &game->engine->event)) {
            if (game->engine->event.type == sfEvtClosed)
                sfRenderWindow_close(game->engine->window->window);
            event_player(game, game->engine->event);
        }
        sfTime elapsed_time = sfClock_restart(game->engine->time->clock);
        game->engine->time->delta = sfTime_asSeconds(elapsed_time);

        for (list_node_t *node = characters->head; node; node = node->next) {
            character = node->value;
            pos = (sfVector2f){rand() % 3 - 1, rand() % 3 - 1};
            sfSprite_move(character->sprite->sprite, pos);
            character->collider->rect.left += pos.x;
            character->collider->rect.top += pos.y;
        }

        update_player(game);
        update_collision(game->engine);

        write_framerate(game->engine);
        clear_window(game->engine);
        display_sprites(game->engine);
        sfRenderWindow_display(game->engine->window->window);
    }

    return 0;
}
