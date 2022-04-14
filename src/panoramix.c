/*
** EPITECH PROJECT, 2022
** Panoramix
** File description:
** panoramix
*/

#include "panoramix.h"
#include <stdlib.h>
#include <stdio.h>

bool check_error(int ac, char **av, params_t *parameters)
{
    if (ac != 5)
        return true;
    parameters->nb_villagers = atoi(av[1]);
    parameters->pot_size = atoi(av[2]);
    parameters->nb_fights = atoi(av[3]);
    parameters->nb_refills = atoi(av[4]);
    if (parameters->nb_villagers <= 0 ||
        parameters->pot_size <= 0 ||
        parameters->nb_fights <= 0 ||
        parameters->nb_refills <= 0) {
        return true;
    }
    return false;
}

int panoramix(int ac, char **av)
{
    params_t parameters;

    if (check_error(ac, av, &parameters)) {
        printf("USAGE: ./panoramix ");
        printf("<nb_villagers> <pot_size> <nb_fights> <nb_refills>\n");
        return 84;
    }
    return 0;
}
