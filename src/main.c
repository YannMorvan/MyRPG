/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"
#include "ice/macro.h"

static int my_rpg(void)
{
    rpg_t *rpg = create_rpg();

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
    if (ac != 1)
        return 84;
    return my_rpg();
}
