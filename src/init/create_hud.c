/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_hud
*/

#include <stdlib.h>

#include "my_rpg.h"
#include "ice/memory.h"

hud_t *init_heart(hud_t *hud)
{
    sfVector2f pos = {20, 490};
    sfVector2f size = {2, 2};
    sfIntRect rect = {0, 0, 16, 16};

    sfSprite_setTextureRect(hud->life->sprite, rect);
    sfSprite_setScale(hud->life->sprite, size);
    sfSprite_setPosition(hud->life->sprite, pos);
    return hud;
}

hud_t *create_hud(engine_t *engine)
{
    hud_t *hud = ice_calloc(1, sizeof(hud_t));

    hud->life = add_sprite_and_texture(engine, "hud", "assets/heart_full.png");
    if (!hud || !hud->life)
        return NULL;
    hud = init_heart(hud);
    return hud;
}
