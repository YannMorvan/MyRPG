/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** create_heal.c
*/

#include <stdlib.h>

#include "ice/memory.h"
#include "my_rpg/game.h"

static void update_spell(rpg_t *rpg, attack_t *attack, list_node_t *node)
{
    spell_t *spell = attack->component;

    spell->count += rpg->engine->time->delta;
    spell->elapsed_time += rpg->engine->time->delta;
    if (spell->elapsed_time > spell->wait_time) {
        set_rect_character(attack->character, (sfIntRect){
            32 * (int)spell->index, 0, 32, 32});
        spell->index++;
        spell->elapsed_time -= spell->wait_time;
        if (spell->index > spell->index_max)
            spell->index = 1;
    }
    sfSprite_setPosition(attack->character->sprite->sprite,
        sfSprite_getPosition(GAME(rpg)->player->character->sprite->sprite));
    move_character(attack->character, (sfVector2f){0, -32});
    if (spell->count > spell->duration) {
        destroy_attack(rpg, attack, node);
    }
}

static void destroy_spell(attack_t *attack)
{
    free(attack->component);
}

static void set_spell_stats(spell_t *spell)
{
    spell->elapsed_time = 0;
    spell->index = 1;
    spell->index_max = 60;
    spell->wait_time = 0.09f;
    spell->duration = 1.0f;
    spell->count = 0;
}

static void modify_sprite(attack_t *attack)
{
    set_scale_character(attack->character, (sfVector2f){3, 3});
    set_rect_character(attack->character, (sfIntRect){0, 0, 32, 32});
    center_character(attack->character);
}

sfBool create_heal(rpg_t *rpg, game_t *game)
{
    attack_t *attack = ice_calloc(1, sizeof(attack_t));
    spell_t *heal = ice_calloc(1, sizeof(spell_t));

    if (!attack || !heal || GAME(rpg)->player->stats->mana < 10)
        return sfFalse;
    GAME(rpg)->player->stats->mana -= 25;
    GAME(rpg)->player->stats->life += 1;
    attack->component = heal;
    set_spell_stats(heal);
    attack->character = create_character(rpg->engine,
        get_middle(GAME(rpg)->player->character->sprite->sprite),
        "heal", "./assets/attacks/heal.png");
    if (!attack->character)
        return sfFalse;
    modify_sprite(attack);
    attack->update = update_spell;
    attack->destroy = destroy_spell;
    return list_add(game->attacks, attack);
}
