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

    if (!file
        || ice_sprintf(buffer,
        "LEVEL=%i\nXP=%i\nSPEED=%i\nINTEL=%i\nCD1=%f\nCD2=%f\nCD3=%f\n",
        stats->level, stats->exp, stats->speed, stats->intel,
        stats->cd[0], stats->cd[1], stats->cd[2]) < 0)
        return sfFalse;
    return fwrite(buffer, ice_strlen(buffer), 1, file) > 0;
}
