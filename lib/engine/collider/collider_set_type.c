/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** collider_set_type.c
*/

#include "engine/struct.h"

void collider_set_type(collider_t *collider, int type)
{
    collider->type = type;
}
