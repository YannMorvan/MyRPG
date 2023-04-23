/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_game.c
*/

#include "my_rpg/game.h"
#include "my_rpg/menu.h"
#include "ice/string.h"

static void destroy_current_npc(rpg_t *rpg)
{
    list_node_t *next;

    if (GAME(rpg)->npcs->size == 0)
        return;
    for (list_node_t *node = GAME(rpg)->npcs->head; node; node = next) {
        next = node->next;
        destroy_npc(rpg, node->value, node);
    }
}

static sfBool sub_scene_map(rpg_t *rpg)
{
    update_player(rpg);
    update_monsters(rpg);
    update_attacks(rpg);
    update_npcs(rpg);
    update_quest(rpg);

    if (GAME(rpg)->player->character->collider->collide & COLLIDER_LADDER
        && GAME(rpg)->monsters->size == 0) {
        play_sound(rpg->engine, "ladder");
        if (GAME(rpg)->quest->name != NULL &&
            ice_strcmp(GAME(rpg)->quest->name, "Survive") == 0)
            GAME(rpg)->quest->progress++;
        destroy_current_npc(rpg);
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
