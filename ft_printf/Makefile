

SRCS		= ./ft_printf.c \
			  ./ft_printf_utils.c 

OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

NAME		= libftprintf.a

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I .

$(NAME) : $(OBJS)
	make all -C ./libft 
	cp ./libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(RM) $(OBJS)
	make clean -C ./libft

fclean : 
	$(RM) $(OBJS)
	make fclean -C ./libft
	$(RM) $(NAME)

re : fclean all

.PHONY:	all clean fclean re
