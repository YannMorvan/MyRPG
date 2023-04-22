/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** display_spell.c
*/

#include "my_rpg/game.h"

hud_t *use_spell(rpg_t *rpg)
{
    sfColor sfGrey = sfColor_fromRGB(128, 128, 128);
    unsigned int i = 0;

    for (;i < 3; i++)
        if (GAME(rpg)->player->stats->cd[i] <= 0.0) {
            rpg->engine->hud->c_mana = GAME(rpg)->player->stats->mana;
            rpg->engine->hud = update_mana(rpg->engine->hud);
            sfSprite_setColor(rpg->engine->hud->spell[i]->sprite, sfGrey);
        }
    return rpg->engine->hud;
}

hud_t *add_spell(engine_t *engine, hud_t *hud, char *path)
{
    sfVector2f pos = {15 + (hud->spl * 45), 495};
    sfVector2f size = {0.6, 0.6};

    hud->spell[hud->spl] = add_sprite_and_texture(engine, path, path);
    if (!hud->spell[hud->spl])
        return NULL;
    sfSprite_setScale(hud->spell[hud->spl]->sprite, size);
    sfSprite_setPosition(hud->spell[hud->spl]->sprite, pos);
    hud->spl++;
    return hud;
}
