/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"
#include "ice/macro.h"
#include "ice/string.h"

static int my_rpg(sfBool debug)
{
    rpg_t *rpg = create_rpg(debug);

    if (!rpg)
        return 84;
    while (sfRenderWindow_isOpen(WINDOW(rpg)))
        if (!rpg->engine->scene(rpg))
            return 84;
    destroy_rpg(rpg);
    return 0;
}

int main(int ac, UNUSED char **av)
{
    if (ac == 2 && !ice_strcmp(av[1], "-d"))
        return my_rpg(sfTrue);
    if (ac != 1)
        return 84;
    return my_rpg(sfFalse);
}
