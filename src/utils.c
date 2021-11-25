/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eomhyeonjun <eomhyeonjun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 04:14:52 by eomhyeonjun       #+#    #+#             */
/*   Updated: 2021/11/26 04:54:55 by eomhyeonjun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t
	get_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);	
}

int
	usleep_loop(int ms)
{
	u_int64_t	start;
	u_int64_t	end;
	int			ret;

	start = get_time();
	end = start + ms;
	ret = 0;
	while (!ret && get_time() < end)
	{
		if (all()->philo_state == PHILO_DIED)
			ret = 1;
        else
		    usleep(100);
	}
	return (ret);
}