/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_sprites.c
*/

#include "engine/struct.h"

void display_sprites(engine_t *engine)
{
    list_t *sprites = engine->sprites->sprites;
    sprite_t *sprite = NULL;

    for (list_node_t *node = sprites->head; node != NULL; node = node->next) {
        sprite = node->value;
        sfRenderWindow_drawSprite(engine->window->window, sprite->sprite, NULL);
    }
}
