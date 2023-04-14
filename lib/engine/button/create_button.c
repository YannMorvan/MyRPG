/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_button.c
*/

#include "ice/memory.h"
#include "engine/collider.h"
#include "engine/character.h"

button_t *create_button(engine_t *engine, sfVector2f pos,
    char *name, char *path)
{
    button_t *button = ice_calloc(1, sizeof(button_t));

    if (!button)
        return NULL;
    button->character = create_character(engine, pos, name, path);
    if (!button->character)
        return NULL;
    collider_set_type(button->character->collider, COLLIDER_BUTTON);
    if (!list_add(engine->buttons, button))
        return NULL;
    return button;
}
