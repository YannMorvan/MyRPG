/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** load_background.c
*/

#include "my_rpg/home.h"

sfBool load_background(rpg_t *rpg)
{
    sprite_t *sprite = add_sprite_and_texture(rpg->engine, "background",
        "./assets/background/background.png");
    sfIntRect rect;

    if (!sprite)
        return sfFalse;
    rect = sfSprite_getTextureRect(sprite->sprite);
    sfSprite_setScale(sprite->sprite, (sfVector2f){
        (float)rpg->engine->window->mode.width / (float)rect.width,
        (float)rpg->engine->window->mode.height / (float)rect.height});
    return sfTrue;
}
