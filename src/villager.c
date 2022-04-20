/*
** EPITECH PROJECT, 2022
** Panoramix
** File description:
** villager
*/

#include "panoramix.h"
#include <stdlib.h>
#include <stdio.h>

void villager_need_potion(villager_t *villager)
{
    printf("Villager %d: Hey Pano wake up! We need more potion.\n",
    villager->id);
    if (villager->params->nb_refills == 0) {
        printf("Villager %d: No more potions, I'm going to sleep now.\n",
        villager->id);
        exit(0);
    }
    pthread_mutex_unlock(&villager->common->druid_sleep_mutex);
    sem_wait(&villager->common->druid_working_mutex);
    sem_post(&villager->common->druid_working_mutex);
}

void villager_fight(villager_t *villager)
{
    villager->nb_fights--;
    printf("Villager %d: Take that roman scum! Only %d left.\n",
    villager->id, villager->nb_fights);
}

void villager_drink(villager_t *villager)
{
    sem_wait(&(villager->common->villagers_semaphore));
    printf("Villager %d: I need a drink... I see %d servings left.\n",
    villager->id, villager->common->nb_potions);
    if (villager->common->nb_potions == 0) {
        villager_need_potion(villager);
    }
    villager->common->nb_potions--;
    sem_post(&(villager->common->villagers_semaphore));
}

void villager_exec(void *data)
{
    villager_t *villager = (villager_t *)data;

    printf("Villager %d: Going into battle !\n", villager->id);
    for (int i = 0; i <= villager->nb_fights + 1; i++) {
        villager_drink(villager);
        villager_fight(villager);
    }
    printf("Villager %d: I'm going to sleep now.\n", villager->id);
}
