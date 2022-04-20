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

villager_t *create_villagers(params_t *params, common_data_t *common)
{
    villager_t *villagers =
    calloc(sizeof(villager_t), params->nb_villagers + 1);

    for (int i = 0; i < params->nb_villagers; i++) {
        villagers[i].id = i;
        villagers[i].params = params;
        villagers[i].common = common;
        villagers[i].nb_fights = params->nb_fights;
    }
    return villagers;
}

int panoramix_run
(params_t *params, common_data_t *common, druid_t *druid)
{
    pthread_t druid_thread;
    villager_t *villagers;
    pthread_t *villager_threads =
    calloc(sizeof(pthread_t), params->nb_villagers + 1);

    if (!villager_threads)
        return 84;
    villagers = create_villagers(params, common);
    if (!villagers)
        return 84;
    pthread_create(&druid_thread, NULL, druid_exec, druid);
    for (int i = 0; i < params->nb_villagers; i++) {
        pthread_create(&villager_threads[i], NULL, villager_exec, &villagers[i]);
    }
    for (int i = 0; i < params->nb_villagers; i++)
        pthread_join(villager_threads[i], NULL);
    pthread_join(druid_thread, NULL);
    free(villager_threads);
    free(villagers);
    return 0;
}

int panoramix(int ac, char **av)
{
    params_t params;
    common_data_t common;
    druid_t druid;

    if (check_error(ac, av, &params)) {
        printf("USAGE: ./panoramix ");
        printf("<nb_villagers> <pot_size> <nb_fights> <nb_refills>\n");
        return 84;
    }
    if (pthread_mutex_init(&common.druid_sleep_mutex, NULL) != 0)
        return 84;
    if (sem_init(&common.druid_working_mutex, 0, 1) != 0)
        return 84;
    if (sem_init(&common.villagers_semaphore, 0, 1) != 0)
        return 84;
    common.nb_potions = params.pot_size;
    druid.params = &params;
    druid.common = &common;
    pthread_mutex_lock(&common.druid_sleep_mutex);
    return panoramix_run(&params, &common, &druid);
}
