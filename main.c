/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eomhyeonjun <eomhyeonjun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:46:01 by eomhyeonjun       #+#    #+#             */
/*   Updated: 2021/11/16 15:34:43 by eomhyeonjun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

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
    return (1);
}

int main(int argc, char **argv)
{
    int res;
    res = parsing_arg(argc, argv);
    
    printf("res : %d\n", res);
    printf("philo_num : %d\n", all()->philo_num);
    printf("time_die : %d\n", all()->time_die);
    printf("time_eat : %d\n", all()->time_eat);
    printf("time_sleep : %d\n", all()->time_sleep);
    printf("must_time : %d\n", all()->must_time);
    return (0);
}