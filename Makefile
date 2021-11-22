NAME = philo

CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

SRCS = \
			all \
			main \
			utils \
			philo_routine \
			act_philo \

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
