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

bonus:			$(BONUS_OBJS) $(BONUS_HEADER)
					@make all -C ./ft_printf
					@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME) $(LIBS)

all:			$(NAME)

run_test: 
		chmod +x test/test_automatized1.sh
		./test/test_automatized1.sh
		chmod +x test/test_makefile.sh
		./test/test_makefile.sh > logs/makefile.log
		chmod +x test/test_funtional.sh
		./test/test_funtional.sh
		chmod +x test/test_funtional2.sh
		./test/test_funtional2.sh
		chmod +x test/test_stress.sh
		./test/test_stress.sh

clean:
				@$(RM) $(OBJS)
				@$(RM) $(BONUS_OBJS)
					@make fclean -C ./ft_printf

fclean:			clean
					@$(RM) $(NAME) $(OBJS)
				rm outfile_shell logs/*

re:				fclean all

.PHONY:			all clean fclean re
