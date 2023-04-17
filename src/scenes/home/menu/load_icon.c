/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** load_icon.c
*/

#include "my_rpg.h"

sfBool load_icon(rpg_t *rpg)
{
    sprite_t *sprite = add_sprite_and_texture(rpg->engine, "home",
        "./assets/icon/icon_large_my_rpg.png");
    sfVector2f scale = {4, 4};
    sfIntRect rect;

    if (!sprite)
        return sfFalse;
    sfSprite_setScale(sprite->sprite, scale);
    rect = sfSprite_getTextureRect(sprite->sprite);
    sfSprite_setPosition(sprite->sprite, (sfVector2f){
        (float)rpg->engine->window->mode.width / 2
        - (float)rect.width * scale.y / 2,
        (float)rpg->engine->window->mode.height / 3.45f
        - (float)rect.width * scale.y / 2});
    return sfTrue;
}
