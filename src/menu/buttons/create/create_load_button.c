/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_load_button.c
*/

#include "my_rpg.h"
#include "ice/macro.h"
#include "my_rpg/menu.h"
#include "my_rpg/game.h"

static void update_load_button_home(void *component, button_t *button)
{
    rpg_t *rpg = (rpg_t *)component;

    update_button_texture(button);
    if (button->state == CLICK) {
        rpg->load = sfTrue;
        rpg->engine->scene = game;
    }
}

static void update_load_button_game(void *component, button_t *button)
{
    rpg_t *rpg = (rpg_t *)component;

    update_button_texture(button);
    if (button->state == CLICK) {
        GAME(rpg)->create_sub_scene = create_buttons_menu_game;
        GAME(rpg)->scene = GAME_MENU;
        rpg->load = sfTrue;
    }
}

button_t *create_load_button(rpg_t *rpg, float index, int scene)
{
    button_t *button = create_button(rpg->engine, (sfVector2f){0, 0},
        "load", "./assets/buttons/load.png");

    if (!button || !set_button(rpg, button, index))
        return NULL;
    button->update = (scene == HOME_ID) ? update_load_button_home :
        update_load_button_game;
    return button;
}
