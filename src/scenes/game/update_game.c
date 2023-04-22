/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_game.c
*/

#include "ice/string.h"
#include "my_rpg/game.h"

sfBool update_game(rpg_t *rpg)
{
    update_engine(rpg->engine, rpg);
    update_player(rpg);
    update_monsters(rpg);
    update_attacks(rpg);
    update_npcs(rpg);
    update_quest(rpg);
    write_framerate(rpg->engine);

    if (GAME(rpg)->player->character->collider->collide & COLLIDER_LADDER
        && GAME(rpg)->monsters->size == 0) {
            if (GAME(rpg)->quest->name != NULL &&
            ice_strcmp(GAME(rpg)->quest->name, "Survive") == 0)
                GAME(rpg)->quest->progress++;
        clear_map(rpg);
        return load_map(rpg);
    }
    return sfTrue;
}
