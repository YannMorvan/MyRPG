/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** print_quest.c
*/

#include <malloc.h>
#include <stdlib.h>

#include "ice/memory.h"
#include "ice/string.h"
#include "my_rpg/game.h"

static void print_sprite(rpg_t *rpg, sfText *text, sfSprite *sprite,
    sfTexture *texture)
{
    sfSprite_setTexture(sprite, texture, sfTrue);
    if (ice_strcmp(GAME(rpg)->quest->name, "Kill") == 0)
        sfSprite_setScale(sprite, (sfVector2f){2.2 , 0.5});
    else
        sfSprite_setScale(sprite, (sfVector2f){4, 0.5});
    sfSprite_setPosition(sprite, (sfVector2f)
        {sfText_getPosition(text).x - 10, sfText_getPosition(text).y - 10});
    sfRenderWindow_drawSprite(rpg->engine->window->window, sprite, NULL);
    sfRenderWindow_drawText(rpg->engine->window->window, text, NULL);
    sfRenderWindow_display(rpg->engine->window->window);
    sfSleep((sfTime){1000000});
    sfText_destroy(text);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

void print_quest(rpg_t *rpg, npc_t *npc)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./assets/fonts/Cinzel.ttf");
    sfTexture *texture = sfTexture_createFromFile(
        "./assets/quest.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfText_setFont(text, font);
    sfText_setString(text, GAME(rpg)->quest->description);
    sfText_setColor(text, sfYellow);
    sfText_setCharacterSize(text, 40);
    sfText_setPosition(text, (sfVector2f)
        {sfSprite_getPosition(npc->character->sprite->sprite).x -
        sfText_getGlobalBounds(text).width / 2 - 10,
        sfSprite_getPosition(npc->character->sprite->sprite).y -
        sfText_getGlobalBounds(text).height - 10});
    print_sprite(rpg, text, sprite, texture);
    sfFont_destroy(font);
}
