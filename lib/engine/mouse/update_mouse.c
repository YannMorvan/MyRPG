/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_mouse.c
*/

#include "engine/struct.h"

void update_mouse(engine_t *engine, mouse_t *mouse)
{
    mouse->pos = sfMouse_getPositionRenderWindow(engine->window->window);
    mouse->posf = sfRenderWindow_mapPixelToCoords(
        engine->window->window, mouse->pos, engine->window->view);
    mouse->collider->rect.left =
        mouse->posf.x - mouse->collider->rect.width / 2;
    mouse->collider->rect.top =
        mouse->posf.y - mouse->collider->rect.height / 2;
}
