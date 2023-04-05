/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_mouse.c
*/

#include "engine/struct.h"

void update_mouse(engine_t *engine, mouse_t *mouse)
{
    mouse->pos = sfMouse_getPositionRenderWindow(engine->window->window);
    mouse->collider->rect.left = (float)mouse->pos.x;
    mouse->collider->rect.top = (float)mouse->pos.y;
}
