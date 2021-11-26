NAME = philo

CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

SRCS = \
			all \
			main \
			utils \
			init_all \
			ft_atoi \
			philo_routine \
			watch_philo_died \
			act_philo \
			print_fuc \

OBJS = $(FIL:.c=.o)
INCS = -I./inc

FIL = \
		$(addsuffix .c, $(addprefix src/, $(SRCS))) \


all : $(NAME)

$(OBJS): %.o : %.c inc/philo.h inc/types.h
	gcc $(CFLAGS) $(INCS) -c -o $@ $<

$(NAME) : $(OBJS)
	gcc $(CFLAGS) $^ -o $@ $(LIBS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
