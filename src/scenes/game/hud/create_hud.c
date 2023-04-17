/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_hud
*/

#include <stdlib.h>

#include "my_rpg.h"
#include "ice/memory.h"

hud_t *lose_life(engine_t *engine, hud_t *hud, unsigned int dmg)
{
    sfVector2f pos = {20 + (((hud->c_life / 2) - 1) * 40), 490};
    sfVector2f size = {2, 2};
    sfIntRect rect = {0, 0, 16, 16};

    if (dmg == 2)
        hud->heart = add_sprite_and_texture(engine, "e_hrt",
        "assets/e_heart.png");
    else
        hud->heart = add_sprite_and_texture(engine, "h_hrt",
        "assets/h_heart.png");
    if (!hud->heart)
        return NULL;
    sfSprite_setTextureRect(hud->heart->sprite, rect);
    sfSprite_setScale(hud->heart->sprite, size);
    sfSprite_setPosition(hud->heart->sprite, pos);
    hud->c_life--;
    return hud;
}

hud_t *take_dmg(engine_t *engine, hud_t *hud, unsigned int dmg)
{
    unsigned int i = 0;

    for (; i <= dmg; i += 2)
        hud = lose_life(engine, hud, 2);
    if (i - dmg == 1)
        hud = lose_life(engine, hud, 1);
    return hud;
}

hud_t *init_heart(engine_t *engine, hud_t *hud)
{
    sfVector2f pos = {20 + ((hud->m_life / 2) * 40), 490};
    sfVector2f size = {2, 2};
    sfIntRect rect = {0, 0, 16, 16};

    hud->heart = add_sprite_and_texture(engine, "f_hrt", "assets/f_heart.png");
    if (!hud->heart)
        return NULL;
    sfSprite_setTextureRect(hud->heart->sprite, rect);
    sfSprite_setScale(hud->heart->sprite, size);
    sfSprite_setPosition(hud->heart->sprite, pos);
    hud->m_life += 2;
    return hud;
}

hud_t *create_hud(engine_t *engine)
{
    hud_t *hud = ice_calloc(1, sizeof(hud_t));

    if (!hud)
        return NULL;
    hud->m_life = 0;
    for (unsigned int i = 0; i < 3; i++)
        hud = init_heart(engine, hud);
    hud->c_life = hud->m_life;
    hud = take_dmg(engine, hud, 5);
    return hud;
}
