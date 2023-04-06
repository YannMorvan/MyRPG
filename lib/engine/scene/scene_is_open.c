/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** scene_is_open.c
*/

#include "engine/struct.h"

sfBool scene_is_open(engine_t *engine, sfBool (*scene)(void *component))
{
    return sfRenderWindow_isOpen(engine->window->window)
        && engine->scene == scene;
}
