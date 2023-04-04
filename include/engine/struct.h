/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** struct.h
*/

#ifndef MY_RPG_STRUCT_H
    #define MY_RPG_STRUCT_H

    #include <SFML/Graphics.h>

    #include "list.h"

    #define COLLIDER_NONE 0b00000000
    #define COLLIDER_CURSOR 0b00000001
    #define COLLIDER_PLAYER 0b00000010
    #define COLLIDER_MONSTER 0b00000100
    #define COLLIDER_WALL 0b00001000

typedef enum collider_static_s {MOVING = 0, STATIC = 1} collider_static_t;

typedef enum collider_collision_s {NO_COLLISION = 0, COLLISION = 1}
    collider_collision_t;

typedef struct colliders_s {
    list_t *colliders;
} colliders_t;

typedef struct collider_s {
    sfFloatRect rect;
    int self_type;
    int collide_type;
    collider_collision_t is_collide;
    collider_static_t is_static;
} collider_t;

typedef struct texture_s {
    char *name;
    sfTexture *texture;
} texture_t;

typedef struct textures_s {
    list_t *textures;
} textures_t;

typedef struct sprite_t {
    texture_t *textures;
    sfSprite *sprite;
} sprite_t;

typedef struct sprites_s {
    list_t *sprites;
} sprites_t;

typedef struct character_s {
    sprite_t *sprite;
    collider_t *collider;
} character_t;

typedef struct delta_time_s {
    sfClock *clock;
    float delta;
} delta_time_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfVideoMode mode;
    char *name;
    sfView *view;
} window_t;

typedef struct engine_s {
    window_t *window;
    delta_time_t *time;
    sfEvent event;
    textures_t *textures;
    sprites_t *sprites;
    colliders_t *colliders;
} engine_t;

#endif /* !MY_RPG_STRUCT_H */
