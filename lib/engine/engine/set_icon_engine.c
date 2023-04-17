/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** set_icon_engine.c
*/

#include "engine/struct.h"

sfBool set_icon_engine(engine_t *engine, char *path)
{
    sfVector2u size;

    engine->window->icon = sfImage_createFromFile(path);
    if (!engine->window->icon)
        return false;
    size = sfImage_getSize(engine->window->icon);
    sfRenderWindow_setIcon(engine->window->window, size.x, size.y,
        sfImage_getPixelsPtr(engine->window->icon));
    return true;
}
