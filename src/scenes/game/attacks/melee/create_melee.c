/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** create_melee.c
*/

#include <malloc.h>

#include "ice/memory.h"
#include "my_rpg/game.h"

static void update_melee(rpg_t *rpg, attack_t *attack, list_node_t *node)
{
    melee_t *melee = attack->component;

    if (attack->character->collider->collide & COLLIDER_MONSTER)
        destroy_attack(rpg, attack, node);
}

static void destroy_melee(attack_t *attack)
{
    free(attack->component);
}

sfBool create_melee(rpg_t *rpg, game_t *game)
{
    attack_t *attack = ice_calloc(1, sizeof(attack_t));
    melee_t *melee = ice_calloc(1, sizeof(melee_t));

    if (!attack || !melee)
        return sfFalse;
    attack->component = melee;
    melee->speed = (sfVector2f){0, 0};
    attack->character = create_character(rpg->engine,
    sfSprite_getPosition(game->player->character->sprite->sprite),
    "melee", "./assets/attacks/sword.png");
    if (!attack->character)
        return sfFalse;
    scale_character(attack->character, (sfVector2f){1.5, 1.5});
    center_character(attack->character);
    attack->update = update_melee;
    attack->destroy = destroy_melee;
    collider_set_type(attack->character->collider, COLLIDER_ATTACK);
    return list_add(game->attacks, attack);
}
