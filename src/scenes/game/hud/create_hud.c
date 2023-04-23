/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_hud
*/

#include <stdlib.h>

#include "my_rpg/game.h"
#include "ice/memory.h"

hud_t *init_heart(engine_t *engine, hud_t *hud, unsigned int f)
{
    sfVector2f pos = {10 + ((hud->m_life / 2) * 40), 30};
    sfVector2f size = {2, 2};

    if (f == 1)
        hud->heart = add_sprite_and_texture(engine, "f_hrt",
        "assets/hud/f_heart.png");
    if (f == 2)
        hud->heart = add_sprite_and_texture(engine, "h_hrt",
        "assets/hud/h_heart.png");
    if (f == 3)
        hud->heart = add_sprite_and_texture(engine, "e_hrt",
        "assets/hud/e_heart.png");
    if (!hud->heart)
        return NULL;
    sfSprite_setScale(hud->heart->sprite, size);
    sfSprite_setPosition(hud->heart->sprite, pos);
    hud->m_life += 2;
    return hud;
}

hud_t *create_inventory(engine_t *engine, hud_t *hud)
{
    sfVector2f pos = {10 + (hud->box * 45), 490};
    sfVector2f size = {2,2};

    hud->inv = add_sprite_and_texture(engine, "inv", "assets/hud/box.png");
    if (!hud->inv)
        return NULL;
    sfSprite_setScale(hud->inv->sprite, size);
    sfSprite_setPosition(hud->inv->sprite, pos);
    hud->box++;
    return hud;
}

hud_t *init_mana_bar(hud_t *hud)
{
    sfVector2f pos = {10, 63};
    sfColor sflGrey = sfColor_fromRGBA(220, 220, 220, 255);

    hud->mana_font = sfRectangleShape_create();
    sfRectangleShape_setPosition(hud->mana_font, pos);
    sfRectangleShape_setFillColor(hud->mana_font, sflGrey);
    sfRectangleShape_setOutlineThickness(hud->mana_font, 2);
    sfRectangleShape_setOutlineColor(hud->mana_font, sfBlack);
    hud->mana_bar = sfRectangleShape_create();
    hud->c_mana = hud->m_mana;
    hud = update_mana(hud);
    return hud;
}

hud_t *create_hud(rpg_t *rpg)
{
    hud_t *hud = ice_calloc(1, sizeof(hud_t));

    if (!hud)
        return NULL;
    hud->m_life = 0;
    hud->m_mana = GAME(rpg)->player->stats->mana;
    hud->box = 0;
    for (unsigned int i = 0; i < 3; i++) {
        hud = init_heart(rpg->engine, hud, 1);
        hud = create_inventory(rpg->engine, hud);
    }
    hud = init_mana_bar(hud);
    hud->c_life = hud->m_mana;
    hud->c_life = GAME(rpg)->player->stats->life;
    hud = update_life(rpg->engine, hud);
    return hud;
}
