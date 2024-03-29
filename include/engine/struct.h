/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** struct.h
*/

#ifndef ENGINE_STRUCT_H
    #define ENGINE_STRUCT_H

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

    #include "list.h"

    #define COLLIDER_NONE 0b00000000
    #define COLLIDER_CURSOR 0b00000001
    #define COLLIDER_PLAYER 0b00000010
    #define COLLIDER_MONSTER 0b00000100
    #define COLLIDER_WALL 0b00001000
    #define COLLIDER_ATTACK 0b00010000
    #define COLLIDER_BUTTON 0b00100000
    #define COLLIDER_LADDER 0b01000000
    #define COLLIDER_NPC 0b10000000

typedef enum collider_static_s {MOVING = 0, STATIC = 1} collider_static_t;

typedef enum button_state_s {IDLE = 0, HOVER = 1, CLICK = 2} button_state_t;

typedef struct collider_s {
    sfFloatRect rect;
    int type;
    int collide;
    collider_static_t is_static;
    list_node_t *node;
} collider_t;

typedef struct texture_s {
    char *name;
    sfTexture *texture;
} texture_t;

typedef struct sprite_t {
    texture_t *texture;
    sfSprite *sprite;
    list_node_t *node;
} sprite_t;

typedef struct character_s {
    sprite_t *sprite;
    collider_t *collider;
} character_t;

typedef struct button_s {
    character_t *character;
    button_state_t state;
    void (*update)(void *component, struct button_s *button);
} button_t;

typedef struct mouse_s {
    sfVector2i pos;
    sfVector2f posf;
    collider_t *collider;
    sfBool left;
    sfBool right;
} mouse_t;

typedef struct delta_time_s {
    sfClock *clock;
    float delta;
} delta_time_t;

typedef struct splash_screen_s {
    sfColor color;
    sfTexture *texture;
    sfSprite *sprite;
} splash_screen_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfVideoMode mode;
    char *name;
    sfView *view;
    sfImage *icon;
    splash_screen_t *splash_screen;
} window_t;

typedef struct hud_s {
    sprite_t *heart;
    sprite_t *inv;
    sprite_t *spell[6];
    sfRectangleShape *mana_font;
    sfRectangleShape *mana_bar;
    unsigned int m_life;
    unsigned int c_life;
    unsigned int m_mana;
    unsigned int c_mana;
    unsigned int box;
} hud_t;

typedef struct text_s {
    sfText *text;
    char *name;
} text_t;

typedef struct font_s {
    sfFont *font;
} font_t;

typedef struct music_s {
    sfMusic *music;
    float volume;
} music_t;

typedef struct sound_s {
    sfSound *sound;
    sfSoundBuffer *buffer;
    char *name;
} sound_t;

typedef struct sounds_s {
    list_t *sounds;
    float volume;
} sounds_t;

typedef struct engine_s {
    window_t *window;
    delta_time_t *time;
    sfEvent event;
    list_t *textures;
    list_t *sprites;
    list_t *colliders;
    list_t *buttons;
    hud_t *hud;
    list_t *fonts;
    list_t *texts;
    mouse_t *mouse;
    music_t *music;
    sounds_t *sounds;
    sfBool (*scene)(void *component);
    sfBool debug;
} engine_t;

#endif /* !ENGINE_STRUCT_H */
