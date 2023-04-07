/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_rpg.c
*/

#include <time.h>
#include <stdlib.h>
#include "my_rpg.h"

rpg_t *create_rpg(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));

    if (!rpg)
        return NULL;
    rpg->engine = create_engine(960, 540, "My Rpg", sfDefaultStyle);
    if (!rpg->engine)
        return NULL;
    if (!set_icon_engine(rpg->engine, "./assets/icon/icon_my_rpg.png"))
        return NULL;
    set_splash_screen(rpg->engine, 5, sfBlack,
        "./assets/icon/icon_large_my_rpg.png");
    display_splash_screen(rpg->engine);
    srand(time(NULL));
    sfRenderWindow_setFramerateLimit(WINDOW(rpg), 60);
    rpg->engine->scene = home;
    return rpg;
}
