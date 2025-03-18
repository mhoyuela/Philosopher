NAME    = philo
USER    = mhoyuela
CFLAGS  = -Wall -Wextra -Werror -g
CC      = clang

SRCS    := init.c monitor.c main.c routine.c utils.c prints.c
OBJS    := ${SRCS:.c=.o}

all: $(NAME)

$(NAME): compiling $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "philosophers compiled!"

%.o: %.c
	@echo "Compiling: $(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

compiling:
	@echo "Compiling philosophers!"

clean:
	@rm -rf $(OBJS)
	@echo "Cleaning philosophers executables."

fclean:
	@rm -rf $(OBJS)
	@rm -rf $(NAME)
	@echo "Fcleaning philosophers."

re: fclean all
	@echo "philosophers recompiled"

norm:
	@echo "Norminette of philosophers files & BONUS."
	@norminette $(SRCS)
	@echo
	@echo "Norminette of LIBFT."
	@norminette $(LIBFT)

.PHONY: all clean fclean re norm compiling