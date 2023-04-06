/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** struct.h
*/

#ifndef MY_RPG_STRUCT_H
    #define MY_RPG_STRUCT_H

    #include "engine.h"

    #define EVENT(rpg) rpg->engine->event
    #define WINDOW(rpg) rpg->engine->window->window

typedef struct rpg_s {
    engine_t *engine;
    void *scene;
} rpg_t;

#endif /* !MY_RPG_STRUCT_H */
