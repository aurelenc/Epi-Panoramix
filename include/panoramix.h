/*
** EPITECH PROJECT, 2022
** Panoramix
** File description:
** panoramix
*/

#pragma once

#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct params_s {
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
} params_t;

typedef struct common_data_s {
    pthread_mutex_t druid_sleep_mutex;
    pthread_mutex_t druid_working_mutex;
    sem_t villagers_semaphore;
} common_data_t;

typedef struct villager_s {
    int id;
    int nb_fights;
    int *nb_potions;
    params_t *params;
    common_data_t *common;
} villager_t;

typedef struct druid_s {
    int *nb_potions;
    params_t *params;
    common_data_t *common;
} druid_t;

int panoramix(int ac, char **av);
void *villager_exec(void *data);
