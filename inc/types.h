/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eomhyeonjun <eomhyeonjun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:50:01 by eomhyeonjun       #+#    #+#             */
/*   Updated: 2021/11/24 08:36:47 by eomhyeonjun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_philo
{
	pthread_t       thread_id;
	pthread_t		monitor;
	int             num;
	int             left_fork;
	int             right_fork;
	int				must_eat;
	int             eat_start;
	uint64_t        eat_end;
}               t_philo;

typedef struct s_all
{
	int					philo_num;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					must_eat;
	int					philo_state;
    uint64_t            start_time;
    pthread_mutex_t		print;
	pthread_mutex_t		state;
	pthread_mutex_t		*forks;
    t_philo     		*philo;
}              t_all;

#endif
