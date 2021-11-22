/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:03:13 by heom              #+#    #+#             */
/*   Updated: 2021/11/22 21:53:26 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_eat(t_philo	*philo) {
	printf("%s", ANSI_COLOR_MAGENTA);
	printf("%d is eating\n", philo->num);
	printf("%s", ANSI_COLOR_RESET);
	return (1);
}

int philo_sleep(t_philo *philo) {
	printf("%s", ANSI_COLOR_BLUE);
	printf("%d is sleeping\n", philo->num);
	printf("%s", ANSI_COLOR_RESET);
	return (1);
}
int philo_think(t_philo *philo) {
	printf("%s", ANSI_COLOR_GREEN);
	printf("%d is thinking\n", philo->num);
	printf("%s", ANSI_COLOR_RESET);
	return (1);
}

int philo_die(t_philo *philo) {
	printf("%s", ANSI_COLOR_RED);
	printf("%d died\n", philo->num);
	printf("%s", ANSI_COLOR_RESET);
	return (1);
}