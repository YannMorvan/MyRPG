/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** display_spell.c
*/

#include "my_rpg/game.h"

hud_t *update_hud(rpg_t *rpg, hud_t *hud, unsigned int i)
{
    if (GAME(rpg)->player->stats->cd[i] <= 0.0) {
        hud->c_mana = GAME(rpg)->player->stats->mana;
        hud = update_mana(hud);
    } else {
        if (i == 2) {
            hud->c_life = GAME(rpg)->player->stats->life;
            hud = update_life(rpg->engine, hud);
            GAME(rpg)->player->stats->life = hud->c_life;
        }
    }
    return hud;
}

hud_t *add_spell(engine_t *engine, hud_t *hud, char *path, unsigned int n)
{
    sfVector2f pos = {15 + (n * 45), 495};
    sfVector2f size = {0.6, 0.6};
    sfColor sfGrey = sfColor_fromRGB(128, 128, 128);

    hud->spell[n] = add_sprite_and_texture(engine, path, path);
    hud->spell[n + 3] = add_sprite_and_texture(engine, path, path);
    if (!hud->spell[n])
        return NULL;
    sfSprite_setScale(hud->spell[n]->sprite, size);
    sfSprite_setPosition(hud->spell[n]->sprite, pos);
    sfSprite_setScale(hud->spell[n + 3]->sprite, size);
    sfSprite_setPosition(hud->spell[n + 3]->sprite, pos);
    sfSprite_setColor(hud->spell[n + 3]->sprite, sfGrey);
    return hud;
}

hud_t *use_spell(rpg_t *rpg)
{
    hud_t *hud = rpg->engine->hud;

    if (GAME(rpg)->player->stats->acces[0] == sfTrue && !hud->spell[0])
        hud = add_spell(rpg->engine, hud, "assets/hud/swordspell.png", 0);
    if (GAME(rpg)->player->stats->acces[1] == sfTrue && !hud->spell[1])
        hud = add_spell(rpg->engine, hud, "assets/hud/firespell.png", 1);
    if (GAME(rpg)->player->stats->acces[2] == sfTrue && !hud->spell[2])
        hud = add_spell(rpg->engine, hud, "assets/hud/healspell.png", 2);
    for (unsigned int i = 0; GAME(rpg)->player->stats->acces[i] == sfTrue
        && i < 3; i++)
        hud = update_hud(rpg, hud, i);
    return hud;
}
