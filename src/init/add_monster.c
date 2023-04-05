/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** add_monster.c
*/

#include <math.h>
#include <stdlib.h>

#include "my_rpg.h"
#include "ice/memory.h"

sfBool add_monster(game_t *game)
{
    monster_t *monster = ice_calloc(1, sizeof(monster_t));
    float angle = (float)((float)(rand() % 360) * M_PI / 180);
    sfVector2f player_pos = sfSprite_getPosition(
        game->player->character->sprite->sprite);
    sfVector2f pos = {500 * cosf(angle) + player_pos.x,
        500 * sinf(angle) + player_pos.y};
    sfIntRect offset;

    if (!monster)
        return sfFalse;
    monster->speed = 100;
    monster->character = create_character(game->engine, pos, "slime",
        "./assets/slime.png");
    if (!monster->character)
        return sfFalse;
    offset = sfSprite_getTextureRect(monster->character->sprite->sprite);
    sfSprite_setOrigin(monster->character->sprite->sprite,
        (sfVector2f){(float)offset.width / 2, (float)offset.height / 2});
    collider_set_type(monster->character->collider, COLLIDER_MONSTER);
    return !list_add(game->monsters, monster);
}
