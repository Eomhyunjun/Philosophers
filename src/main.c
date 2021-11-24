/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eomhyeonjun <eomhyeonjun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:46:01 by eomhyeonjun       #+#    #+#             */
/*   Updated: 2021/11/24 08:36:49 by eomhyeonjun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_philo(void)
{
    int     i;

    i = 0;
    while (i < all()->philo_num)
    {
        all()->philo[i].num = i;
        all()->philo[i].eat_end = all()->start_time;
        if (i == 0)
            all()->philo[i].right_fork = all()->philo_num - 1;
        else
            all()->philo[i].right_fork = all()->philo[i].num - 1;
        all()->philo[i].left_fork = all()->philo[i].num;
        all()->philo[i].must_eat = all()->must_eat;
        i++;
    }
    return (SUCCES);
}

int main(int argc, char **argv)
{
    int res;

    res = init_all(argc, argv);

    if (!res)
        res = init_philo();
    if (!res)
        lifecycle_thread_philo();
    else
    {
        // 에러 메세지 보내기
    }
    // 할당해제
    return (0);
}
