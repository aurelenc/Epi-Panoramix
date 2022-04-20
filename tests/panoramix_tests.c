/*
** EPITECH PROJECT, 2022
** Panoramix
** File description:
** panoramix_tests
*/

#include <criterion/criterion.h>
#include <semaphore.h>
#include <pthread.h>
#include "../include/panoramix.h"

bool check_error(int ac, char **av, params_t *parameters);
void druid_refill(druid_t *druid);
void villager_need_potion(villager_t *villager);
void villager_fight(villager_t *villager);
void villager_drink(villager_t *villager);

Test(github_action, test)
{
    cr_assert(0 == 0);
}

Test(druid, refill)
{
    druid_t druid;
    common_data_t common;
    params_t params;

    params.nb_refills = 2;
    params.pot_size = 5;
    druid.params = &params;
    druid.common = &common;
    druid_refill(&druid);
    cr_assert(druid.common->nb_potions == 5);
    cr_assert(druid.params->nb_refills == 1);
}

Test(druid, refill_zero)
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

Test(druid, druid_exec)
{
    druid_t druid;
    common_data_t common;
    params_t params;

    params.nb_refills = 1;
    params.pot_size = 5;
    common.nb_potions = 0;
    druid.params = &params;
    druid.common = &common;
    druid_refill(&druid);
    cr_assert(druid.common->nb_potions == 5);
}

Test(check_error, invalid_params_true)
{
    params_t params;
    char *av[] = {"panoramix", "0"};
    char *one[] = {"panoramix", "0", "5", "3", "1"};
    char *two[] = {"panoramix", "3", "0", "3", "1"};
    char *three[] = {"panoramix", "3", "5", "0", "1"};
    char *four[] = {"panoramix", "3", "5", "3", "0"};

    cr_assert(check_error(2, av, &params) == 1);
    cr_assert(check_error(5, one, &params) == 1);
    cr_assert(check_error(5, two, &params) == 1);
    cr_assert(check_error(5, three, &params) == 1);
    cr_assert(check_error(5, four, &params) == 1);
}

Test(check_error, invalid_params_false)
{
    params_t params;
    char *av_full[] = {"panoramix", "3", "5", "3", "1"};

    cr_assert(check_error(5, av_full, &params) == 0);
}

Test(panoramix, check_error)
{
    char *av[] = {"panoramix", "0"};

    cr_assert(panoramix(2, av) == 84);
}

Test(villager, fight)
{
    villager_t villager;
    common_data_t common;
    params_t params;

    params.nb_fights = 2;
    params.pot_size = 5;
    villager.params = &params;
    villager.common = &common;
    villager.id = 1;
    villager.nb_fights = 2;
    villager_fight(&villager);
    cr_assert(villager.nb_fights == 1);
}

// Test(villager, drink)
// {
//     villager_t villager;
//     common_data_t common;
//     params_t params;

//     params.nb_fights = 2;
//     params.pot_size = 5;
//     common.nb_potions = 5;
//     villager.params = &params;
//     villager.common = &common;
//     villager.id = 1;
//     villager.nb_fights = 2;
//     villager_drink(&villager);
//     cr_assert(common.nb_potions == 4);
// }

// Test(villager, need_potion)
// {
//     villager_t villager;
//     common_data_t common;
//     params_t params;

//     params.nb_fights = 2;
//     params.pot_size = 5;
//     params.nb_refills = 1;
//     common.nb_potions = 0;
//     villager.params = &params;
//     villager.common = &common;
//     villager.id = 1;
//     villager.nb_fights = 1;
//     villager_need_potion(&villager);
//     cr_assert(common.nb_potions == 4);
// }

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
