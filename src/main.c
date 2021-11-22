/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eomhyeonjun <eomhyeonjun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:46:01 by eomhyeonjun       #+#    #+#             */
/*   Updated: 2021/11/22 20:26:32 by eomhyeonjun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int philo_eat{

// }
// int philo_sleep{

// }
// int philo_think{

// }

// int philo_die{

// }

int parsing_arg(int argc, char **argv)
{
    if (argc == 5 || argc == 6)
    {
        all()->philo_num = ft_atoi(argv[1]);
        all()->time_die = ft_atoi(argv[2]);
        all()->time_eat = ft_atoi(argv[3]);
        all()->time_sleep = ft_atoi(argv[4]);
        all()->must_time = -1;
        if (argc == 6)
            all()->must_time = ft_atoi(argv[5]); 
    }
    else
        return (ERR);
    printf("----인자 확인------\n");
    printf("philo_num : %d\n", all()->philo_num);
    printf("time_die : %d\n", all()->time_die);
    printf("time_eat : %d\n", all()->time_eat);
    printf("time_sleep : %d\n", all()->time_sleep);
    printf("must_time : %d\n", all()->must_time);
    return (1);
}

void *counter(void *philo){
    t_philo *now_philo;
    now_philo = (t_philo *)philo;
    printf("%d번째 철학자가 태어났습니다 응애\n", now_philo->num);
    return (0);
}

int generatePhilo() {
    int i;
    int j;
    void *now_philo;

    all()->philo = (t_philo *)malloc(sizeof(t_philo) * (all()->philo_num));
    if (!all()->philo)
        return (ERR);

    i = 0;
    while (i < all()->philo_num)
    {
        all()->philo[i].num = i + 1;
        now_philo = &(all()->philo[i]);
        pthread_create(&all()->philo[i].thread_id, NULL, &counter, now_philo);
        i++;
    }
    j = 0;
    while (j < all()->philo_num)
    {
        pthread_join(all()->philo[j].thread_id, NULL);
        j++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    int res;
    res = parsing_arg(argc, argv);
    if (res)
    {
        // 필로소퍼들 생성 -> 실패시 exit
        generatePhilo();
        // 쓰레드 핸들
        
    }
    else
    {
        // 에러 메세지 보내기
    }
    // 할당해제
    return (0);
}

    // value chk
    // printf("res : %d\n~", res);
    // printf("philo_num : %d\n", all()->philo_num);
    // printf("time_die : %d\n", all()->time_die);
    // printf("time_eat : %d\n", all()->time_eat);
    // printf("time_sleep : %d\n", all()->time_sleep);
    // printf("must_time : %d\n", all()->must_time);