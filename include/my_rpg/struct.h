/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** struct.h
*/

#ifndef MY_RPG_STRUCT_H
    #define MY_RPG_STRUCT_H

    #include "engine.h"

    #define EVENT(rpg) rpg->engine->event
    #define WINDOW(rpg) rpg->engine->window->window

typedef struct parse_s {
    char *name;
    long long value;
    char *string;
} parse_t;

typedef struct config_s {
    char *title;
    int width;
    int height;
    int fps;
    char *icon;
    char *splash;
} config_t;

typedef struct rpg_s {
    engine_t *engine;
    void *scene;
} rpg_t;

#endif /* !MY_RPG_STRUCT_H */
