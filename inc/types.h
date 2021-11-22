/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:50:01 by eomhyeonjun       #+#    #+#             */
/*   Updated: 2021/11/22 21:43:16 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_philo
{
	pthread_t       thread_id;
	int             num;
	int             left_fork;
	int             right_fork;
	int             eat_start;
	int             eat_end;
}               t_philo;

typedef struct s_all
{
	int					philo_num;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					must_time;	
	pthread_mutex_t		*forks;
    pthread_mutex_t		print;
    t_philo     *philo;
}              t_all;

#endif
