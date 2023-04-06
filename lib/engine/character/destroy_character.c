/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_character.c
*/

#include <malloc.h>

#include "engine/sprite.h"

void destroy_character(engine_t *engine, character_t *character)
{
    list_remove_node(engine->sprites, character->sprite->node);
    destroy_sprite(character->sprite);
    list_remove_node(engine->colliders, character->collider->node);
    free(character->collider);
    free(character);
}
