/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** create_spell.c
*/


#include <malloc.h>

#include "ice/memory.h"
#include "my_rpg/game.h"

static void update_spell(rpg_t *rpg, attack_t *attack, list_node_t *node)
{
    spell_t *spell = attack->component;

    move_character(rpg->engine, attack->character, spell->speed);
    if (attack->character->collider->collide & COLLIDER_WALL)
        destroy_attack(rpg, attack, node);
}

static void destroy_spell(attack_t *attack)
{
    free(attack->component);
}

sfVector2f get_middle(sfSprite *sprite)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);

    pos.x -= rect.width / 2;
    pos.y -= rect.height / 2;
    return pos;
}

sfBool create_spell(rpg_t *rpg, game_t *game)
{
    attack_t *attack = ice_calloc(1, sizeof(attack_t));
    spell_t *spell = ice_calloc(1, sizeof(spell_t));

    if (!attack || !spell)
        return sfFalse;
    attack->component = spell;
    attack->is_attack = sfTrue;
    spell->speed = (sfVector2f) {-200, 0};
    attack->character = create_character(rpg->engine,
    get_middle(GAME(rpg)->player->character->sprite->sprite),
        "spell", "./assets/attacks/1.png");
    if (!attack->character)
        return sfFalse;
    scale_character(attack->character, (sfVector2f) {0.05, 0.05});
    center_character(attack->character);
    attack->update = update_spell;
    attack->destroy = destroy_spell;
    collider_set_type(attack->character->collider, COLLIDER_ATTACK);
    return !list_add(game->attacks, attack);
}
