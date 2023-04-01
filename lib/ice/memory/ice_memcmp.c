/*
** EPITECH PROJECT, 2023
** libice
** File description:
** ice_memcmp.c
*/

#include "ice/assert.h"

int ice_memcmp(const void *s1, const void *s2, ull_t n)
{
    ASSERT_RET(s1, 0);
    ASSERT_RET(s2, 0);
    for (ull_t i = 0; i < n; i++)
        if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
            return ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
    return 0;
}