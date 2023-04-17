/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_hud
*/

#include <stdlib.h>

#include "my_rpg.h"
#include "ice/memory.h"

hud_t *init_heart(engine_t *engine, hud_t *hud)
{
    sfVector2f pos = {20 + (hud->life * 40), 490};
    sfVector2f size = {2, 2};
    sfIntRect rect = {0, 0, 16, 16};

    hud->heart = add_sprite_and_texture(engine, "hud", "assets/heart_full.png");
    if (!hud->heart)
        return NULL;
    sfSprite_setTextureRect(hud->heart->sprite, rect);
    sfSprite_setScale(hud->heart->sprite, size);
    sfSprite_setPosition(hud->heart->sprite, pos);
    return hud;
}

hud_t *create_hud(engine_t *engine)
{
    hud_t *hud = ice_calloc(1, sizeof(hud_t));

    if (!hud)
        return NULL;
    for (; hud->life < 3; hud->life++)
        hud = init_heart(engine, hud);
    return hud;
}
