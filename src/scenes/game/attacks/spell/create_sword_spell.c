/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** create_spell.c
*/


#include <math.h>
#include <stdlib.h>

#include "ice/memory.h"
#include "my_rpg/game.h"

static void update_spell(rpg_t *rpg, attack_t *attack, list_node_t *node)
{
    spell_t *spell = attack->component;

    spell->elapsed_time += rpg->engine->time->delta;
    if (spell->elapsed_time > spell->wait_time) {
        set_rect_character(attack->character, (sfIntRect){
            33 * (int)spell->index, 0, 33, 15});
        spell->index++;
        spell->elapsed_time -= spell->wait_time;
        if (spell->index > spell->index_max)
            spell->index = 1;
    }
    move_character(attack->character, spell->speed);
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
    spell->angle = (float)get_angle(sfSprite_getPosition
        (GAME(rpg)->player->character->sprite->sprite),
        rpg->engine->mouse->posf);
    spell->speed = (sfVector2f){
        cosf(spell->angle) * 4, sinf(spell->angle) * 4};
    spell->elapsed_time = 0;
    spell->index = 1;
    spell->index_max = 3;
    spell->wait_time = 0.09f;
    GAME(rpg)->player->stats->mana -= 10;
}

static void modify_sprite(attack_t *attack, spell_t *spell)
{
    set_scale_character(attack->character, (sfVector2f){1.5, 1.5});
    set_rect_character(attack->character, (sfIntRect){0, 0, 33, 15});
    center_character(attack->character);
    sfSprite_setRotation(attack->character->sprite->sprite,
        spell->angle * 180 / M_PI - 180);
}

sfBool create_sword_spell(rpg_t *rpg, game_t *game)
{
    attack_t *attack = ice_calloc(1, sizeof(attack_t));
    spell_t *spell = ice_calloc(1, sizeof(spell_t));

    if (!attack || !spell || GAME(rpg)->player->stats->mana < 10)
        return sfFalse;
    attack->component = spell;
    set_spell_stats(rpg, spell);
    attack->character = create_character(rpg->engine,
        get_middle(GAME(rpg)->player->character->sprite->sprite),
        "sword", "./assets/attacks/sword_spell.png");
    if (!attack->character)
        return sfFalse;
    modify_sprite(attack, spell);
    attack->update = update_spell;
    attack->destroy = destroy_spell;
    collider_set_type(attack->character->collider, COLLIDER_ATTACK);
    play_sound(rpg->engine, "sword");
    return list_add(game->attacks, attack);
}
