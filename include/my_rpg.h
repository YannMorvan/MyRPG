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
    #include "engine/button.h"

    #define EVENT(game) game->engine->event
    #define WINDOW(game) game->engine->window->window

//
// STRUCT
//

typedef struct monster_s {
    character_t *character;
    int speed;
} monster_t;

typedef struct player_s {
    character_t *character;
    int speed;
    sfVector2f velocity;
} player_t;

typedef struct game_s {
    engine_t *engine;
    player_t *player;
    list_t *monsters;
    hud_t *hud;
} game_t;

//
// CREATE
//
/**
 * @brief Create hud objects
 * 
 * @param engine The engine
 * @return hud_t* The hud
*/
hud_t *create_hud(engine_t *engine);

/**
 * @brief Create a game object
 *
 * @return game_t* The game
 */
game_t *create_game(void);

/**
 * @brief Create a player object
 *
 * @param engine The engine
 * @return player_t* The player
 */
player_t *create_player(engine_t *engine);

/**
 * @brief Create a pause button
 *
 * @param game The game
 * @return button_t* The button
 */
button_t *create_pause_button(game_t *game);

/**
 * @brief Create a monster object
 *
 * @param engine The engine
 * @return monster_t* The monster
 */
sfBool add_monster(game_t *game);


//
// EVENT
//

/**
 * @brief Handle the events of the game
 *
 * @param game The game
 */
void event_game(game_t *game);

/**
 * @brief Handle the events of the player
 *
 * @param game The game
 * @param event The event
 */
void event_player(game_t *game, sfEvent event);

//
// UPDATE
//

/**
 * @brief Update the game
 *
 * @param game The game
 */
void update_game(game_t *game);

/**
 * @brief Update the player
 *
 * @param game The game
 */
void update_player(game_t *game);

/**
 * @brief Update the monsters
 *
 * @param game The game
 */
void update_monsters(game_t *game);

//
// DISPLAY
//

/**
 * @brief Display the game
 *
 * @param game The game
 */
void display_game(game_t *game);

//
// DESTROY
//

/**
 * @brief Destroy the game
 *
 * @param game The game
 */
void destroy_game(game_t *game);

/**
 * @brief Destroy the player
 *
 * @param player The player
 */
void destroy_player(player_t *player);

/**
 * @brief Destroy the monster
 *
 * @param monster The monster
 */
void destroy_monster(monster_t *monster);

#endif /* !MY_RPG_MY_RPG_H */
