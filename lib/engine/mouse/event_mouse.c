/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event_mouse.c
*/

#include "engine/struct.h"

void event_mouse(engine_t *engine, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.button == sfMouseLeft)
            engine->mouse->left = true;
        if (event.mouseButton.button == sfMouseRight)
            engine->mouse->right = true;
    }
    if (event.type == sfEvtMouseButtonReleased) {
        if (event.mouseButton.button == sfMouseLeft)
            engine->mouse->left = false;
        if (event.mouseButton.button == sfMouseRight)
            engine->mouse->right = false;
    }
}
