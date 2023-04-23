/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** display_spell.c
*/

#include "my_rpg/game.h"

hud_t *use_spell(rpg_t *rpg)
{
    hud_t *hud = rpg->engine->hud;
    sfColor sfGrey = sfColor_fromRGB(128, 128, 128);
    unsigned int i = 0;

    hud = display_spell(rpg->engine, hud, "assets/hud/swordspell.png", 0);
    hud = display_spell(rpg->engine, hud, "assets/hud/firespell.png", 1);
    hud = display_spell(rpg->engine, hud, "assets/hud/healspell.png", 2);
    for (;i < 3; i++)
        if (GAME(rpg)->player->stats->cd[i] <= 0.0) {
            hud->c_mana = GAME(rpg)->player->stats->mana;
            hud = update_mana(hud);
        } else
            sfSprite_setColor(hud->spell[i]->sprite, sfGrey);
    return hud;
}

hud_t *display_spell(engine_t *engine, hud_t *hud, char *path, unsigned int n)
{
    sfVector2f pos = {15 + (n * 45), 495};
    sfVector2f size = {0.6, 0.6};

    hud->spell[n] = add_sprite_and_texture(engine, path, path);
    if (!hud->spell[n])
        return NULL;
    sfSprite_setScale(hud->spell[n]->sprite, size);
    sfSprite_setPosition(hud->spell[n]->sprite, pos);
    return hud;
}
