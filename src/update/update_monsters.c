/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_monsters.c
*/

#include <math.h>

#include "my_rpg.h"
#include "ice/macro.h"

void update_monsters(game_t *game)
{
    sfVector2f offset = {0, 0};
    sfVector2f player_pos = sfSprite_getPosition(
        game->player->character->sprite->sprite);
    sfVector2f monster_pos;
    sfVector2f distance;
    float length;

    for (list_node_t *node = game->monsters->head; node; node = node->next) {
        monster_t *monster = node->value;
        monster_pos = sfSprite_getPosition(monster->character->sprite->sprite);
        distance.x = player_pos.x - monster_pos.x;
        distance.y = player_pos.y - monster_pos.y;
        length = ABS(distance.x) + ABS(distance.y);
        if (length < 1)
            continue;
        offset.x = (distance.x / length) * (float)monster->speed;
        offset.y = (distance.y / length) * (float)monster->speed;
        move_character(game->engine, monster->character, offset);
    }
}
