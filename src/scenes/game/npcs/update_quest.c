/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** update_quest.c
*/

#include "my_rpg/game.h"
#include "ice/memory.h"

static void print_success(rpg_t *rpg)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./assets/fonts/Cinzel.ttf");

    sfText_setFont(text, font);
    sfText_setString(text, "Quest completed");
    sfText_setColor(text, sfYellow);
    sfText_setCharacterSize(text, 40);
    sfText_setPosition(text, (sfVector2f)
        {sfSprite_getPosition(GAME(rpg)->player->character->sprite->sprite).x -
        sfText_getGlobalBounds(text).width / 2,
        sfSprite_getPosition(GAME(rpg)->player->character->sprite->sprite).y -
        sfText_getGlobalBounds(text).height - 10});
    sfRenderWindow_drawText(rpg->engine->window->window, text, NULL);
    sfRenderWindow_display(rpg->engine->window->window);
    sfSleep((sfTime){1000000});
    sfText_destroy(text);
    sfFont_destroy(font);
}

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
        print_success(rpg);
    }
}
