/*
** EPITECH PROJECT, 2023
** libice/string
** File description:
** ice_strndup.c
*/

#include <stdlib.h>

#include "ice/int.h"
#include "ice/macro.h"
#include "ice/string.h"
#include "ice/assert.h"

char *ice_strndup(const char *str, ull_t n)
{
    ull_t len = MIN(ice_strlen(str), n);
    char *new = malloc(sizeof(char) * (len + 1));

    ASSERT_RET(new && str, NULL);
    ice_strncpy(new, str, len);
    return new;
}
