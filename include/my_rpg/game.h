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

typedef enum game_scene_s {
    GAME_MAP = 0,
    GAME_MENU = 1,
    GAME_SETTINGS = 2
} game_scene_t;

typedef struct spell_s {
    sfVector2f speed;
    float angle;
    unsigned int index;
    unsigned int index_max;
    float elapsed_time;
    float wait_time;
    float duration;
    float count;
} spell_t;

typedef struct attack_s {
    character_t *character;
    void (*update)(rpg_t *rpg, struct attack_s *attack, list_node_t *node);
    void (*destroy)(struct attack_s *attack);
    void *component;
} attack_t;

typedef struct slime_s {
    sfVector2f speed;
    int health;
    unsigned int damages;
} slime_t;

typedef struct monster_s {
    character_t *character;
    void (*update)(rpg_t *rpg, struct monster_s *monster, list_node_t *node);
    void (*destroy)(struct monster_s *monster);
    void *component;
} monster_t;

typedef struct npc_s {
    character_t *character;
    void (*update)(rpg_t *rpg, struct npc_s *npc);
    void (*destroy)(struct npc_s *npc);
    void *component;
} npc_t;

typedef struct quest_s {
    char *name;
    char *description;
    int reward;
    int progress;
    int objective;
} quest_t;

typedef struct stats_s {
    unsigned int level;
    unsigned int exp;
    unsigned int speed;
    unsigned int intel;
    unsigned int mana;
    float elapsed_time;
    float wait_time;
    float cd[3];
    sfBool acces[3];
} stats_t;

typedef struct player_s {
    character_t *character;
    stats_t *stats;
    sfVector2f velocity;
    sfBool interact;
} player_t;

typedef struct map_s {
    list_t *floors;
    list_t *walls;
} map_t;

typedef struct game_s {
    player_t *player;
    list_t *monsters;
    list_t *attacks;
    list_t *npcs;
    hud_t *hud;
    quest_t *quest;
    map_t *map;
    sprite_t *icon;
    int size_index;
    game_scene_t scene;
    int stage;
    sfBool (*create_sub_scene)(rpg_t *rpg);
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
sfBool update_game(rpg_t *rpg);

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
 * @brief Create the map
 *
 * @param rpg The rpg
 * @return map_t* The map
 */
map_t *create_map(rpg_t *rpg);

/**
 * @brief Load the map
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
sfBool load_map(rpg_t *rpg);

/**
 * @brief Clear the map
 *
 * @param rpg The rpg
 */
void clear_map(rpg_t *rpg);

/**
 * @brief Destroy the map
 *
 * @param rpg The rpg
 */
void destroy_map(rpg_t *rpg);

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

/**
 * @brief Set the floor
 *
 * @param rpg The rpg
 * @param pos The position
 * @param offset The offset
 * @return sfBool False if an error occurred
 */
sfBool set_floor(rpg_t *rpg, sfVector2i pos, sfVector2i offset);

/**
 * @brief Set the ladder
 *
 * @param rpg The rpg
 * @param pos The position
 * @param offset The offset
 * @return sfBool False if an error occurred
 */
sfBool set_ladder(rpg_t *rpg, sfVector2i pos, sfVector2i offset);

/**
 * @brief Set the player on the map
 *
 * @param rpg The rpg
 * @param pos The position
 * @param offset The offset
 * @return sfBool False if an error occurred
 */
sfBool set_player(rpg_t *rpg, sfVector2i pos, sfVector2i offset);

/**
 * @brief Set a monster on the map
 *
 * @param rpg The rpg
 * @param pos The position
 * @param offset The offset
 * @return sfBool False if an error occurred
 */
sfBool set_monster(rpg_t *rpg, sfVector2i pos, sfVector2i offset);

/**
 * @brief Set a npc on the map
 *
 * @param rpg The rpg
 * @param pos The position
 * @param offset The offset
 * @return sfBool False if an error occurred
 */
sfBool set_npc(rpg_t *rpg, sfVector2i pos, sfVector2i offset);

//
// Hud
//

/**
 * @brief Create the hud
 *
 * @param engine The engine
 * @return hud_t* The hud
*/
hud_t *create_hud(engine_t *engine);

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
// Npc
//

/**
 * @brief Print the quest
 *
 * @param rpg The rpg
 * @param npc The npc
 */
void print_quest(rpg_t *rpg, npc_t *npc);

/**
 * @brief Update the npcs
 *
 * @param rpg The rpg
 */
void update_npcs(rpg_t *rpg);

/**
 * @brief Destroy the npcs
 *
 * @param rpg The rpg
 */
void destroy_npcs(rpg_t *rpg);

/**
 * @brief Destroy the npc
 *
 * @param rpg The rpg
 * @param npc The npc
 * @param node The node
 */
void destroy_npc(rpg_t *rpg, npc_t *npc, list_node_t *node);

/**
 * @brief Create the quest
 *
 * @param rpg The rpg
 */
quest_t *create_quest(void);

/**
 * @brief Update the quest
 *
 * @param rpg The rpg
 * @param quest The quest
 */
void update_quest(rpg_t *rpg);

/**
 * @brief Create the npc
 *
 * @param rpg The rpg
 * @param game The game
 * @return npc_t* The npc
 */
sfBool create_devil(rpg_t *rpg, game_t *game);

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
 * @brief Create the attacks
 *
 * @param rpg The rpg
 * @param game The game
 * @return attack_t* The attack
 */
sfBool create_attacks(game_t *game);


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
 * @brief Get the angle
 *
 * @param player_pos The Player pos
 * @param target The Target pos
 */
double get_angle(sfVector2f player_pos, sfVector2f target);

/**
 * @brief Get the Middle of the Sprite
 *
 * @param sprite The Sprite
 */
sfVector2f get_middle(sfSprite *sprite);

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
sfBool create_heal(rpg_t *rpg, game_t *game);

/**
 * @brief Create the attack
 *
 * @param rpg The rpg
 * @param game The game
 * @return attack_t* The attack
 */
sfBool create_spell(rpg_t *rpg, game_t *game);

/**
 * @brief Create the attack
 *
 * @param rpg The rpg
 * @param game The game
 * @return attack_t* The attack
 */
sfBool create_sword_spell(rpg_t *rpg, game_t *game);

//
// Button
//

/**
 * @brief Create the button
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
sfBool create_buttons_map_game(rpg_t *rpg);

/**
 * @brief Create the game scene
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
sfBool create_buttons_menu_game(rpg_t *rpg);

/**
 * @brief Create the settings scene
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
sfBool create_buttons_settings_game(rpg_t *rpg);

/**
 * @brief Create the pause button
 *
 * @param rpg The rpg
 * @return button_t* The button
 */
button_t *create_pause_button(rpg_t *rpg);

/**
 * @brief Create the save button
 *
 * @param rpg The rpg
 * @param index The index
 * @param scene The scene
 * @return button_t* The button
 */
button_t *create_save_button(rpg_t *rpg , float index, int scene);

//
// Save
//

/**
 * @brief Save the game
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
sfBool save_game(rpg_t *rpg);

/**
 * @brief Load the game
 *
 * @param rpg The rpg
 * @return sfBool False if an error occurred
 */
sfBool load(rpg_t *rpg);

#endif /* !MY_RPG_GAME_H */
