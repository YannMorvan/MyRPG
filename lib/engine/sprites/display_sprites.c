/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** display_sprites.c
*/

#include "engine/struct.h"
#include "engine/collider.h"

void display_sprites(engine_t *engine)
{
    list_t *sprites = engine->sprites;
    sprite_t *sprite;

    for (list_node_t *node = sprites->head; node; node = node->next) {
        sprite = node->value;
        sfRenderWindow_drawSprite(engine->window->window, sprite->sprite, NULL);
    }
    if (engine->debug)
        debug_collider(engine);
}
