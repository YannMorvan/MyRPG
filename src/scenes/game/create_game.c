/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_game.c
*/

#include "ice/memory.h"
#include "my_rpg/game.h"

static sfBool create_background(rpg_t *rpg)
{
    sprite_t *background = add_sprite_and_texture(rpg->engine,
        "background", "./assets/background/dungeon.jpg");
    sfFloatRect rect;

    if (!background)
        return sfFalse;
    rect = sfSprite_getGlobalBounds(background->sprite);
    sfSprite_setScale(background->sprite, (sfVector2f){
        (float)rpg->engine->window->mode.width / rect.width,
        (float)rpg->engine->window->mode.height / rect.height
    });
    return sfTrue;
}

game_t *create_game(rpg_t *rpg)
{
    game_t *game = ice_calloc(1, sizeof(game_t));
    rpg->scene = game;

    if (!game || !create_background(rpg))
        return NULL;
    game->hud = create_hud(rpg->engine);
    game->monsters = list_create();
    game->npcs = list_create();
    game->player = create_player(rpg->engine);
    if (rpg->load && !load(rpg))
        return NULL;
    game->map = create_map(rpg);
    game->quest = create_quest();
    game->stage = 0;
    return (!game->monsters || !game->hud
        || !create_buttons_map_game(rpg) || !create_attacks(game)
        || !create_sound(rpg->engine, "ladder",
        "./assets/sounds/ladder.ogg")) ? NULL : game;
}
