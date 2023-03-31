/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_framerate.c
*/

#include "ice/printf.h"
#include "engine/struct.h"

sfBool write_framerate(engine_t *engine)
{
    float fps = 1 / sfTime_asSeconds(engine->time->delta);
    char str[25];

    if (ice_sprintf(str, "FPS: %.2f", fps) < 0)
        return sfFalse;
    sfRenderWindow_setTitle(engine->window, str);
    return sfTrue;
}
