/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** create_quest.c
*/

#include "my_rpg/game.h"
#include "ice/memory.h"

quest_t *create_quest(void)
{
    quest_t *quest = ice_calloc(1, sizeof(quest_t));

    if (!quest)
        return NULL;
    quest->name = NULL;
    quest->description = NULL;
    quest->reward = 0;
    quest->progress = 0;
    quest->objective = 0;
    return quest;
}
