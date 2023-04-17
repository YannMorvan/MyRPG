/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_hud
*/

#include <stdlib.h>

#include "my_rpg.h"
#include "ice/memory.h"

hud_t *create_hud(engine_t *engine)
{
    hud_t *hud = ice_calloc(1, sizeof(hud_t));
    sfVector2f pos = {20, 20};
    sfVector2f size = {3, 3};
    sfIntRect rect = {13, 47, 111, 8};

    if (!hud)
        return NULL;
    hud->sprite = add_sprite_and_texture(engine, "hud", "assets/hud.png");
    if (!hud->sprite)
        return NULL;
    sfSprite_setTextureRect(hud->sprite->sprite, rect);
    sfSprite_setScale(hud->sprite->sprite, size);
    sfSprite_setPosition(hud->sprite->sprite, pos);
    return hud;
}
