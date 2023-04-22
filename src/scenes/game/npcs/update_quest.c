/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** update_quest.c
*/

#include "my_rpg/game.h"
#include "ice/memory.h"

static void update_spell_acces(rpg_t *rpg)
{
    for (int i = 0; i < 3; i++) {
        if (GAME(rpg)->player->stats->acces[i] == sfFalse) {
            GAME(rpg)->player->stats->acces[i] = sfTrue;
            return;
        }
    }
    GAME(rpg)->player->stats->exp += GAME(rpg)->quest->reward;
}

void update_quest(rpg_t *rpg)
{
    if (GAME(rpg)->quest->name == NULL)
        return;
    if (GAME(rpg)->quest->progress == GAME(rpg)->quest->objective) {
        GAME(rpg)->quest->name = NULL;
        GAME(rpg)->quest->description = NULL;
        GAME(rpg)->quest->reward = 0;
        GAME(rpg)->quest->progress = 0;
        GAME(rpg)->quest->objective = 0;
        update_spell_acces(rpg);
    }
}
