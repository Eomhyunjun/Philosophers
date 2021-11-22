#ifndef PHILO_H
# define PHILO_H

# define ERR 1
# define ODD 0
# define EVEN 1

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include "types.h"

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

t_all
*all(void);

int
ft_atoi(const char *str);

void
*philo_routine(void *philo);

int
philo_eat(t_philo *philo);

int
philo_sleep(t_philo *philo);

int
philo_think(t_philo *philo);

int
philo_die(t_philo *philo);

#endif