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

hud_t *create_hud(engine_t *engine)
{
    hud_t *hud = ice_calloc(1, sizeof(hud_t));

    if (!hud)
        return NULL;
    hud->m_life = 0;
    hud->box = 0;
    hud->spl = 0;
    for (unsigned int i = 0; i < 3; i++) {
        hud = init_heart(engine, hud, 1);
        hud = create_inventory(engine, hud);
    }
    hud = create_inventory(engine, hud);
    hud->c_life = hud->m_life;
    hud = add_spell(engine, hud, "assets/hud/swordspell.png");
    hud = add_spell(engine, hud, "assets/hud/firespell.png");
    return hud;
}
