/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:02:25 by heom              #+#    #+#             */
/*   Updated: 2021/11/22 21:46:14 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_routine(void *philo){
    t_philo *now_philo;
    
	now_philo = (t_philo *)philo;
    printf("%d번째 철학자가 태어났습니다 응애\n", now_philo->num);

	philo_eat(now_philo);
	philo_sleep(now_philo);
	philo_think(now_philo);
	philo_die(now_philo);
    return (0);
}