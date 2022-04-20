/*
** EPITECH PROJECT, 2022
** Panoramix
** File description:
** panoramix_tests
*/

#include <criterion/criterion.h>
#include <semaphore.h>
#include "../include/panoramix.h"

void druid_refill(druid_t *druid);
void villager_fight(villager_t *villager);

Test(github_action, test)
{
    cr_assert(0 == 0);
}

Test(druid, refill)
{
    druid_t druid;
    common_data_t common;
    params_t params;

    params.nb_refills = 1;
    params.pot_size = 5;
    druid.params = &params;
    druid.common = &common;
    druid_refill(&druid);
    cr_assert(druid.common->nb_potions == 5);
    cr_assert(druid.params->nb_refills == 0);
}

// Test(villager, fight)
// {
//     villager_t villager;
//     common_data_t common;
//     params_t params;

//     sem_init(&common.villagers_semaphore, 0, 1);
//     params.nb_fights = 1;
//     params.nb_refills = 1;
//     params.pot_size = 5;
//     villager.params = &params;
//     villager.common = &common;
//     villager.nb_fights = 1;
//     villager.id = 0;
//     villager_fight(&villager);
//     cr_assert(villager.nb_fights == 0);
// }
