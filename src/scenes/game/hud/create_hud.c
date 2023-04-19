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
    sfVector2f pos = {20 + ((hud->m_life / 2) * 40), 490};
    sfVector2f size = {2, 2};
    sfIntRect rect = {0, 0, 16, 16};

    if (f == 1)
        hud->heart = add_sprite_and_texture(engine,
        "f_hrt", "assets/hud/f_heart.png");
    if (f == 2)
        hud->heart = add_sprite_and_texture(engine, "h_hrt",
        "assets/hud/h_heart.png");
    if (f == 3)
        hud->heart = add_sprite_and_texture(engine, "e_hrt",
        "assets/hud/e_heart.png");
    if (!hud->heart)
        return NULL;
    sfSprite_setTextureRect(hud->heart->sprite, rect);
    sfSprite_setScale(hud->heart->sprite, size);
    sfSprite_setPosition(hud->heart->sprite, pos);
    hud->m_life += 2;
    return hud;
}

hud_t *create_inventory(hud_t *hud)
{
    sfVector2f pos = {0, 0};
    sfVector2f size = {1,1};
    sfColor fill = sfColor_fromRGB(128, 128, 128);

    hud->inv = ice_calloc(1, sizeof(rect_t));
    hud->inv->rec = sfRectangleShape_create();
    sfRectangleShape_setPosition(hud->inv->rec, pos);
    sfRectangleShape_setSize(hud->inv->rec, size);
    sfRectangleShape_setFillColor(hud->inv->rec, fill);
    sfRectangleShape_setOutlineThickness(hud->inv->rec, 2);
    sfRectangleShape_setOutlineColor(hud->inv->rec, sfBlack);
    return hud;
}

hud_t *create_hud(engine_t *engine)
{
    hud_t *hud = ice_calloc(1, sizeof(hud_t));

    if (!hud)
        return NULL;
    hud->m_life = 0;
    for (unsigned int i = 0; i < 3; i++)
        hud = init_heart(engine, hud, 1);
    hud->c_life = hud->m_life;
    hud = create_inventory(hud);
    return hud;
}
