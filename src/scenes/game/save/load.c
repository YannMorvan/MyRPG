/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** load.c
*/

#include "my_rpg.h"
#include "my_rpg/game.h"

sfBool load(rpg_t *rpg)
{
    list_t *list = parse_file("./assets/config/save");
    stats_t *stats = GAME(rpg)->player->stats;

    if (!list)
        return sfFalse;
    stats->level = (int)get_parse_value(list, "LEVEL");
    stats->exp = (int)get_parse_value(list, "XP");
    stats->speed = (int)get_parse_value(list, "SPEED");
    stats->intel = (int)get_parse_value(list, "INTEL");
    stats->cd[0] = (float)get_parse_value(list, "SP1");
    stats->cd[1] = (float)get_parse_value(list, "SP2");
    stats->cd[2] = (float)get_parse_value(list, "SP3");
    return stats->cd[0] >= 0 && stats->cd[1] >= 0 && stats->cd[2] >= 0;
}
