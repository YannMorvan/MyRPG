/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_buttons.c
*/

#include "engine/struct.h"

void update_buttons(engine_t *engine, void *component)
{
    button_t *button;

    for (list_node_t *node = engine->buttons->head; node; node = node->next) {
        button = (button_t *)node->value;
        if (button->character->collider->collide_type == COLLIDER_CURSOR)
            button->state = (engine->mouse->left) ? CLICK : HOVER;
        else
            button->state = IDLE;
        if (button->update)
            button->update(component, button);
    }
}
