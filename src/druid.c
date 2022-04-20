/*
** EPITECH PROJECT, 2022
** Panoramix
** File description:
** druid
*/

#include "panoramix.h"
#include <stdio.h>

void druid_refill(druid_t *druid)
{
    druid->params->nb_refills--;
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only \
make %d more refills after this one.\n",
    druid->params->nb_refills);
    druid->common->nb_potions = druid->params->pot_size;
    if (druid->params->nb_refills == 0)
        printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
}

void druid_exec(void *data)
{
    druid_t *druid = (druid_t *)data;

    sem_wait(&druid->common->druid_working_mutex);
    printf("Druid: I'm ready... but sleepy...\n");
    while (druid->params->nb_refills > 0) {
        pthread_mutex_lock(&(druid->common->druid_sleep_mutex));
        druid_refill(druid);
    }
    sem_post(&druid->common->druid_working_mutex);
}
