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
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only");
    printf(" make %d more refills after this one.\n",
    druid->params->nb_refills);
    druid->common->nb_potions = druid->params->pot_size;
}

void *druid_exec(void *data)
{
    druid_t *druid = (druid_t *)data;

    printf("Druid: I'm ready... but sleepy...\n");
    while (druid->params->nb_refills > 0) {
        // pthread_mutex_lock(&(druid->common->druid_sleep_mutex));
        // pthread_mutex_lock(&(druid->common->druid_working_mutex));
        druid_refill(druid);
        // pthread_mutex_unlock(&(druid->common->druid_working_mutex));

    }
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return data;
}