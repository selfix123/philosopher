NAME	=	philo

GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
WHITE	=	\033[0m

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra 
RM		=	rm -f
#-fsanitize=thread
SRCS	=	philo.c\
			argc_checker.c\
			init_all.c\
			is_int.c\
			ft_liatoi.c\
			ft_strlen.c\
			ft_bzero.c\
			checks.c\
			atoi.c\
			get_time.c\
			mutex.c\

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling . . .$(WHITE)\n"
	@ $(CC) $(CFLAGS) $(SRCS) -o $(NAME)

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@echo "$(BLUE)Create objects$(WHITE)"

clean:
	@$(RM) $(OBJS)
	@$(RM) $(LDIR)*.o
	@echo "$(RED)Removes objects$(WHITE)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Removes executables$(WHITE)"

re: fclean all