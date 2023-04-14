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
    static float fps = 0;
    static float time = 0;
    static ui_t frame = 0;
    char str[108];

    fps += 1 / engine->time->delta;
    time += engine->time->delta;
    frame++;
    if (time < 1)
        return sfTrue;
    fps /= (float)frame;
    if (ice_sprintf(str, "%s | FPS: %.2f", engine->window->name, fps) < 0)
        return sfFalse;
    sfRenderWindow_setTitle(engine->window->window, str);
    time = 0;
    fps = 0;
    frame = 0;
    return sfTrue;
}
