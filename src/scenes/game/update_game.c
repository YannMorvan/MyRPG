/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_game.c
*/

#include "my_rpg/menu.h"
#include "my_rpg/game.h"

static sfBool sub_scene_map(rpg_t *rpg)
{
    update_player(rpg);
    update_monsters(rpg);
    update_attacks(rpg);

    if (GAME(rpg)->player->character->collider->collide & COLLIDER_LADDER
        && GAME(rpg)->monsters->size == 0) {
        play_sound(rpg->engine, "ladder");
        clear_map(rpg);
        return load_map(rpg);
    }
    return sfTrue;
}

sfBool update_game(rpg_t *rpg)
{
    update_engine(rpg->engine, rpg);
    write_framerate(rpg->engine);
    if (GAME(rpg)->create_sub_scene) {
        clear_sub_scene(rpg);
        GAME(rpg)->create_sub_scene(rpg);
        GAME(rpg)->create_sub_scene = NULL;
    }
    return (GAME(rpg)->scene == GAME_MAP) ? sub_scene_map(rpg) : sfTrue;
}
