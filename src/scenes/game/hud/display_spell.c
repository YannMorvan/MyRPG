/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** display_spell.c
*/

#include "my_rpg/game.h"

sprite_t *use_spell(sprite_t *spell)
{
    sfColor sfGrey = sfColor_fromRGB(128, 128, 128);

    sfSprite_setColor(spell->sprite, sfGrey);
    return spell;
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
