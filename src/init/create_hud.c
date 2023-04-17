/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_hud
*/

#include <stdlib.h>

#include "my_rpg.h"
#include "ice/memory.h"

hud_t *init_mana_bar(engine_t *engine, hud_t *hud)
{
    sfVector2f pos = {20, 500};
    sfVector2f size = {2, 3};
    sfIntRect rect = {13, 54, 111, 8};

    hud->mana = add_sprite_and_texture(engine, "hud", "assets/hud.png");
    if (!hud->mana)
        return NULL;
    sfSprite_setTextureRect(hud->mana->sprite, rect);
    sfSprite_setScale(hud->mana->sprite, size);
    sfSprite_setPosition(hud->mana->sprite, pos);
    return hud;
}

hud_t *init_life_bar(engine_t *engine, hud_t *hud)
{
    sfVector2f pos = {20, 470};
    sfVector2f size = {3, 3};
    sfIntRect rect = {13, 47, 111, 8};

    hud->life = add_sprite_and_texture(engine, "hud", "assets/hud.png");
    if (!hud->life)
        return NULL;
    sfSprite_setTextureRect(hud->life->sprite, rect);
    sfSprite_setScale(hud->life->sprite, size);
    sfSprite_setPosition(hud->life->sprite, pos);
    return hud;
}

hud_t *create_hud(engine_t *engine)
{
    hud_t *hud = ice_calloc(1, sizeof(hud_t));

    if (!hud)
        return NULL;
    hud = init_life_bar(engine, hud);
    hud = init_mana_bar(engine, hud);
    return hud;
}
