/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** destroy_engine.c
*/

#include <malloc.h>

#include "engine/mouse.h"
#include "engine/window.h"
#include "engine/button.h"
#include "engine/sprite.h"
#include "engine/texture.h"

void destroy_engine(engine_t *engine)
{
    list_destroy_node(engine->textures, (void *)destroy_texture);
    list_destroy_node(engine->sprites, (void *)destroy_sprite);
    list_destroy_node(engine->colliders, free);
    list_destroy_node(engine->buttons, (void *)destroy_button);
    sfClock_destroy(engine->time->clock);
    destroy_window(engine);
    free(engine->time);
    free(engine->mouse);
    free(engine);
}
