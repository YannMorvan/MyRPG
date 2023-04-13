/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** game.h
*/

#ifndef MY_RPG_GAME_H
    #define MY_RPG_GAME_H

    #include "my_rpg/struct.h"

//
// Struct
//

typedef struct spell_s {
    sfVector2f speed;
} spell_t;

typedef struct attack_s {
    character_t *character;
    void (*update)(rpg_t *rpg, struct attack_s *attack, list_node_t *node);
    void (*destroy)(struct attack_s *attack);
    void *component;
    sfBool is_attack;
} attack_t;

typedef struct slime_s {
    sfVector2f speed;
} slime_t;

typedef struct monster_s {
    character_t *character;
    void (*update)(rpg_t *rpg, struct monster_s *monster, list_node_t *node);
    void (*destroy)(struct monster_s *monster);
    void *component;
} monster_t;

typedef struct player_s {
    character_t *character;
    int speed;
    sfVector2f velocity;
} player_t;

typedef struct game_s {
    player_t *player;
    list_t *monsters;
    list_t *attacks;
} game_t;

    #define GAME(rpg) ((game_t *)rpg->scene)

//
// Main functions
//

/**
 * @brief Create the game scene
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
game_t *create_game(rpg_t *rpg);

/**
 * @brief Event of the game scene
 *
 * @param rpg The rpg
 */
void event_game(rpg_t *rpg);

/**
 * @brief Update the game scene
 *
 * @param rpg The rpg
 */
void update_game(rpg_t *rpg);

/**
 * @brief Display the game scene
 *
 * @param rpg The rpg
 */
void display_game(rpg_t *rpg);

/**
 * @brief Destroy the game scene
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
sfBool destroy_game(rpg_t *rpg);

//
// Map
//

/**
 * @brief Load the map
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
sfBool load_map(rpg_t *rpg);

/**
 * @brief Get the tile position
 *
 * @param pos The position
 * @param offset The offset
 * @return sfVector2f The tile position
 */
sfVector2f get_tile_pos(sfVector2i pos, sfVector2i offset);

/**
 * @brief Set the wall
 *
 * @param rpg The rpg
 * @param map The map
 * @param pos The position
 * @param offset The offset
 * @return sfBool False if an error occurred
 */
sfBool set_wall(rpg_t *rpg, char **map, sfVector2i pos, sfVector2i offset);

//
// Player
//

/**
 * @brief Create the player
 *
 * @param engine The engine
 * @return player_t* The player
 */
player_t *create_player(engine_t *engine);

/**
 * @brief Event of the player
 *
 * @param rpg The rpg
 * @param event The event
 * @return sfBool False if an error occurred
 */
sfBool event_player(rpg_t *rpg, sfEvent event);

/**
 * @brief Update the player
 *
 * @param rpg The rpg
 */
void update_player(rpg_t *rpg);

/**
 * @brief Destroy the player
 *
 * @param rpg The rpg
 */
void destroy_player(player_t *player);

//
// Monster
//

/**
 * @brief Update the monsters
 *
 * @param rpg The rpg
 */
void update_monsters(rpg_t *rpg);

/**
 * @brief Destroy the monsters
 *
 * @param rpg The rpg
 */
void destroy_monsters(rpg_t *rpg);

/**
 * @brief Destroy the monster
 *
 * @param rpg The rpg
 * @param monster The monster
 * @param node The node
 */
void destroy_monster(rpg_t *rpg, monster_t *monster, list_node_t *node);

/**
 * @brief Create the monster
 *
 * @param rpg The rpg
 * @param game The game
 * @return monster_t* The monster
 */
sfBool create_slime(rpg_t *rpg, game_t *game);

//
// Attack
//


/**
 * @brief Update the attacks
 *
 * @param rpg The rpg
 */
void update_attacks(rpg_t *rpg);

/**
 * @brief Destroy the attacks
 *
 * @param rpg The rpg
 */
void destroy_attacks(rpg_t *rpg);

/**
 * @brief Destroy the attack
 *
 * @param rpg The rpg
 * @param attack The attack
 * @param node The node
 */
void destroy_attack(rpg_t *rpg, attack_t *attack, list_node_t *node);

/**
 * @brief Create the attack
 *
 * @param rpg The rpg
 * @param game The game
 * @return attack_t* The attack
 */
sfBool create_spell(rpg_t *rpg, game_t *game);

//
// Button
//

/**
 * @brief Create the start button
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
button_t *create_pause_button(rpg_t *rpg);


#endif /* !MY_RPG_GAME_H */
