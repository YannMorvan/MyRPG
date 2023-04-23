/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-yann.morvan
** File description:
** update_quest.c
*/

#include "my_rpg/game.h"
#include "ice/memory.h"

static void print_square(rpg_t *rpg, sfText *text)
{
    sfTexture *texture = sfTexture_createFromFile(
        "./assets/quest.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){2.7, 0.5});
    sfSprite_setPosition(sprite, (sfVector2f)
        {sfText_getPosition(text).x - 10, sfText_getPosition(text).y - 10});
    sfRenderWindow_drawSprite(rpg->engine->window->window, sprite, NULL);
    sfRenderWindow_drawText(rpg->engine->window->window, text, NULL);
    sfRenderWindow_display(rpg->engine->window->window);
    sfSleep((sfTime){1000000});
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

static void print_success(rpg_t *rpg)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./assets/fonts/Cinzel.ttf");

    sfText_setFont(text, font);
    sfText_setString(text, "Quest completed");
    sfText_setColor(text, sfYellow);
    sfText_setCharacterSize(text, 40);
    sfText_setPosition(text, sfView_getCenter(rpg->engine->window->view));
    sfText_setPosition(text, (sfVector2f)
        {sfText_getPosition(text).x - sfText_getGlobalBounds(text).width / 2,
        sfText_getPosition(text).y - sfText_getGlobalBounds(text).height / 2});
    print_square(rpg, text);
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
