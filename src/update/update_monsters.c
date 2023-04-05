/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_monsters.c
*/

#include <math.h>

#include "my_rpg.h"
#include "ice/macro.h"

static void update_monster(game_t *game, list_node_t *node,
    sfVector2f player_pos)
{
    monster_t *monster = node->value;
    sfVector2f monster_pos = sfSprite_getPosition(
        monster->character->sprite->sprite);
    sfVector2f distance = {
        player_pos.x - monster_pos.x, player_pos.y - monster_pos.y};
    float length = ABS(distance.x) + ABS(distance.y);
    if (length < 1)
        return;
    move_character(game->engine, monster->character,
        (sfVector2f){(distance.x / length) * (float)monster->speed,
        (distance.y / length) * (float)monster->speed});
    if (monster->character->collider->collide_type == COLLIDER_PLAYER) {
        list_remove_node(game->monsters, node);
        destroy_monster(monster);
    }
}

void update_monsters(game_t *game)
{
    sfVector2f player_pos = sfSprite_getPosition(
        game->player->character->sprite->sprite);
    list_node_t *next_node;

    for (list_node_t *node = game->monsters->head; node; node = next_node) {
        next_node = node->next;
        update_monster(game, node, player_pos);
    }
}
