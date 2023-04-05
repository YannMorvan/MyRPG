/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_engine.c
*/

#include <malloc.h>

#include "engine/struct.h"
#include "engine/sprite.h"

void destroy_engine(engine_t *engine)
{
    list_destroy(engine->textures->textures);
    list_destroy_node(engine->sprites->sprites, (void *)destroy_sprite);
    list_destroy_node(engine->colliders->colliders, free);
    free(engine->textures);
    free(engine->sprites);
    free(engine->colliders);
    sfClock_destroy(engine->time->clock);
    free(engine->time);
    sfRenderWindow_destroy(engine->window->window);
    sfView_destroy(engine->window->view);
    free(engine->window->name);
    free(engine->window);
    free(engine);
}
