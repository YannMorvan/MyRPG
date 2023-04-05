/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_mouse.c
*/

#include "ice/memory.h"
#include "engine/collider.h"

mouse_t *create_mouse(engine_t *engine)
{
    mouse_t *mouse = ice_calloc(1, sizeof(mouse_t));

    if (!mouse)
        return NULL;
    mouse->collider = create_collider(engine, (sfFloatRect){0, 0, 1, 1},
        COLLIDER_CURSOR, MOVING);
    if (!mouse->collider)
        return NULL;
    return mouse;
}
