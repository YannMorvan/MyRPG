/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_rpg.c
*/

#include <time.h>
#include <stdlib.h>
#include "my_rpg.h"

static config_t *get_config(void)
{
    config_t *config = malloc(sizeof(config_t));
    list_t *list = parse_file("./assets/config/rpg.config");

    if (!config || !list)
        return NULL;
    config->width = (int)get_parse_value(list, "WIDTH");
    config->height = (int)get_parse_value(list, "HEIGHT");
    config->title = get_parse_string(list, "TITLE");
    config->icon = get_parse_string(list, "ICON");
    config->splash = get_parse_string(list, "SPLASH");
    config->fps = (int)get_parse_value(list, "FRAMERATE");
    destroy_parse(list);
    if (config->width <= 0 || config->height <= 0 || !config->title
        || !config->icon || !config->splash || config->fps <= 0)
        return NULL;
    return config;
}

static void destroy_config(config_t *config)
{
    free(config->title);
    free(config->icon);
    free(config->splash);
    free(config);
}

rpg_t *create_rpg(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    config_t *config = get_config();

    if (!rpg || !config)
        return NULL;
    rpg->engine = create_engine(config->width, config->height,
        config->title, sfDefaultStyle);
    if (!rpg->engine)
        return NULL;
    if (!set_icon_engine(rpg->engine, config->icon))
        return NULL;
    set_splash_screen(rpg->engine, 5, sfBlack, config->splash);
    display_splash_screen(rpg->engine);
    srand(time(NULL));
    sfRenderWindow_setFramerateLimit(WINDOW(rpg), config->fps);
    rpg->engine->scene = home;
    destroy_config(config);
    return rpg;
}
