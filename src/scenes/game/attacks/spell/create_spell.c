/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** create_spell.c
*/


#include <malloc.h>
#include <math.h>

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

void set_spell_direction(rpg_t *rpg, spell_t *spell)
{
    sfVector2f player =
    sfSprite_getPosition(GAME(rpg)->player->character->sprite->sprite);
    sfVector2f direction =
    (sfVector2f) {rpg->engine->mouse->pos.x - player.x,
    rpg->engine->mouse->pos.y - player.y};
    spell->angle = atan2(direction.y, direction.x) * 180 / 3.14;

    spell->speed.x = cos(spell->angle * 3.14 / 180) * 200;
    spell->speed.y = sin(spell->angle * 3.14 / 180) * 200;
}

sfBool create_spell(rpg_t *rpg, game_t *game)
{
    attack_t *attack = ice_calloc(1, sizeof(attack_t));
    spell_t *spell = ice_calloc(1, sizeof(spell_t));

    if (!attack || !spell)
        return sfFalse;
    attack->component = spell;
    attack->is_attack = sfTrue;
    set_spell_direction(rpg, spell);
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
