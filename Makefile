NAME			= pipex

SRCS			= ./mandatory/pipex.c \
				./mandatory/utils.c 
				
BONUS_SRCS 		= ./bonus/pipex_bonus.c \
				./bonus/utils_bonus.c \
				./bonus/execute_bonus.c \

HEADER			= ./mandatory/pipex.h

BONUS_HEADER	= ./bonus/pipex_bonus.h

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g3 -fsanitize=address
RM				= rm -f

LIBS			= -L ./ft_printf -lftprintf

OBJS			= $(SRCS:.c=.o)

BONUS_OBJS		= $(BONUS_SRCS:.c=.o)

$(NAME):		$(OBJS) $(HEADER)
					@make all -C ./ft_printf
					@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

#bonus:			$(BONUS_OBJS) $(BONUS_HEADER)
#					@make all -C ./ft_printf
#					@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME) $(LIBS)

all:			$(NAME)

clean:
				@$(RM) $(OBJS)
#				@$(RM) $(BONUS_OBJS)
					@make fclean -C ./ft_printf

fclean:			clean
					@$(RM) $(NAME) $(OBJS)

re:				fclean all

.PHONY:			all clean fclean re
