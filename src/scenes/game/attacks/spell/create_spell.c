/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** create_spell.c
*/


#include <malloc.h>
#include <math.h>

#include "ice/memory.h"
#include "my_rpg/game.h"

static void update_spell_texture(attack_t *attack, spell_t *spell)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(attack->character->sprite->sprite);
    set_rect_character(attack->character, (sfIntRect) {rect.width * spell->index, 0, rect.width, rect.height});
}

static void update_spell(rpg_t *rpg, attack_t *attack, list_node_t *node)
{
    spell_t *spell = attack->component;

    spell->elapsed_time += rpg->engine->time->delta;
    if (spell->elapsed_time > spell->wait_time) {
        printf("%i\n", spell->index);
        update_spell_texture(attack, spell);
        spell->index++;
        spell->elapsed_time -= spell->wait_time;
        if (spell->index > spell->index_max)
            spell->index = 1;
    }
    move_character(rpg->engine, attack->character, spell->speed);
    if (attack->character->collider->collide & COLLIDER_WALL ||
        attack->character->collider->collide & COLLIDER_MONSTER)
        destroy_attack(rpg, attack, node);
}

static void destroy_spell(attack_t *attack)
{
    free(attack->component);
}

static void set_spell_stats(rpg_t *rpg, spell_t *spell)
{
    spell->angle = get_angle(sfSprite_getPosition
    (GAME(rpg)->player->character->sprite->sprite),
        rpg->engine->mouse->posf);
    spell->speed =
    (sfVector2f) {cos(spell->angle) * 200, sin(spell->angle) * 200};
    spell->elapsed_time = 0;
    spell->index = 1;
    spell->index_max = 60;
    spell->wait_time = 0.01;
}

sfBool create_spell(rpg_t *rpg, game_t *game)
{
    attack_t *attack = ice_calloc(1, sizeof(attack_t));
    spell_t *spell = ice_calloc(1, sizeof(spell_t));
    sfFloatRect rect;

    if (!attack || !spell)
        return sfFalse;
    attack->component = spell;
    set_spell_stats(rpg, spell);
    attack->character = create_character(rpg->engine,
        get_middle(GAME(rpg)->player->character->sprite->sprite),
        "spell", "./assets/attacks/fireball.png");
    if (!attack->character)
        return sfFalse;
    rect = sfSprite_getGlobalBounds(attack->character->sprite->sprite);
    set_rect_character(attack->character, (sfIntRect) {rect.width / 60 * spell->index, 0, rect.width / 60, rect.height});
    center_character(attack->character);
    attack->update = update_spell;
    attack->destroy = destroy_spell;
    collider_set_type(attack->character->collider, COLLIDER_ATTACK);
    return !list_add(game->attacks, attack);
}
