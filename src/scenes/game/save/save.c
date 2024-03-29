/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** save.c
*/

#include <stdio.h>

#include "ice/printf.h"
#include "ice/string.h"
#include "my_rpg/game.h"

sfBool save_game(rpg_t *rpg)
{
    FILE *file = fopen("./assets/config/save", "w");
    stats_t *stats = GAME(rpg)->player->stats;
    char buffer[1024] = {0};

    if (!file || ice_sprintf(buffer,
        "LEVEL=%i\nXP=%i\nSPEED=%i\nINTEL=%i\n"
        "SP1=%i\nSP2=%i\nSP3=%i\nSTAGE=%i\n",
        stats->level, stats->exp, stats->speed, stats->intel,
        stats->acces[0], stats->acces[1], stats->acces[2],
        GAME(rpg)->stage) < 0)
        return sfFalse;
    return fwrite(buffer, ice_strlen(buffer), 1, file) == 1
        && !fclose(file);
}
