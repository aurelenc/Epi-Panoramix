/*
** EPITECH PROJECT, 2022
** Panoramix
** File description:
** panoramix
*/

#pragma once

#include <stdbool.h>

typedef struct params_s {
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
} params_t;

int panoramix(int ac, char **av);
