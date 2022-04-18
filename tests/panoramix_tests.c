/*
** EPITECH PROJECT, 2022
** Panoramix
** File description:
** panoramix_tests
*/

#include <criterion/criterion.h>
#include "../include/panoramix.h"

void druid_refill(druid_t *druid);

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
