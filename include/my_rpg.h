/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_rpg.h
*/

#ifndef MY_RPG_MY_RPG_H
    #define MY_RPG_MY_RPG_H

    #include "engine/window.h"
    #include "engine/engine.h"
    #include "engine/sprite.h"
    #include "engine/texture.h"
    #include "engine/character.h"
    #include "engine/collider.h"

typedef struct game_s {
    engine_t *engine;
} game_t;

game_t *get_game(void);

#endif /* !MY_RPG_MY_RPG_H */
