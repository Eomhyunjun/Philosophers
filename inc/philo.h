#ifndef PHILO_H
# define PHILO_H

# define ERR 1
# define SUCCES 0
# define ODD 0
# define EVEN 1

# include <unistd.h>
#include <sys/time.h>
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

# define PRINT_EAT 0
# define PRINT_GRAP_FORK 1
# define PRINT_SLEEP 2
# define PRINT_THINK 3
# define PRINT_DIE 4

# define PHILO_DIED 0
# define PHILO_ALIVE 1

t_all
*all(void);

int
init_all(int argc, char **argv);

int
parsing_arg(int argc, char **argv);

int
lifecycle_thread_philo(void);

int
create_thread(int odd);

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

void
print_fuc(t_philo *philo, int type);

/*
**  -------- UTILS --------
*/

uint64_t
get_time(void);	

int
usleep_loop(int ms);

int
ft_atoi(const char *str);

#endif