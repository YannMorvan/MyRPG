/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_game.c
*/

#include "my_rpg.h"
#include "my_rpg/menu.h"
#include "my_rpg/home.h"
#include "my_rpg/game.h"
#include "ice/string.h"

static void display_end_menu(rpg_t *rpg)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./assets/fonts/Cinzel.ttf");

    sfRenderWindow_clear(rpg->engine->window->window, sfBlack);
    sfText_setFont(text, font);
    sfText_setString(text, "You win !");
    sfText_setCharacterSize(text, 100);
    sfText_setColor(text, sfYellow);
    sfText_setPosition(text, (sfVector2f){rpg->engine->window->mode.width / 2
        - sfText_getLocalBounds(text).width / 2,
        rpg->engine->window->mode.height / 2 -
        sfText_getLocalBounds(text).height / 2});
    sfRenderWindow_drawText(rpg->engine->window->window, text, NULL);
    sfRenderWindow_display(rpg->engine->window->window);
    sfText_destroy(text);
    sfFont_destroy(font);
}

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

static void update_all(rpg_t *rpg)
{
    update_player(rpg);
    update_monsters(rpg);
    update_attacks(rpg);
    update_npcs(rpg);
    update_quest(rpg);
}

static sfBool sub_scene_map(rpg_t *rpg)
{
    update_all(rpg);
    if (GAME(rpg)->stage == 10) {
        display_end_menu(rpg);
        sfSleep((sfTime){1000000});
        rpg->engine->scene = home;
    }
    if (GAME(rpg)->player->character->collider->collide & COLLIDER_LADDER
        && GAME(rpg)->monsters->size == 0) {
        play_sound(rpg->engine, "ladder");
        if (GAME(rpg)->quest->name != NULL &&
            ice_strcmp(GAME(rpg)->quest->name, "Survive") == 0)
            GAME(rpg)->quest->progress++;
        GAME(rpg)->stage++;
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
