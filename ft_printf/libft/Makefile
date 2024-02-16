# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 12:22:38 by cvarela-          #+#    #+#              #
#    Updated: 2023/09/27 16:39:54 by cvarela-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = libft.a
CC = gcc

RM = rm -f

RUN = ranlib

LIB = ar crs

CFLAGS = -Wall -Wextra -Werror -I.

SRCS =  ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
       ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	   ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
	   ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
	   ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	   ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
	   ft_toupper.c
OBJS = ${SRCS:.c=.o}

BONUS_SRCS = ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c ft_lstclear_bonus.c \
			ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c \
			ft_lstnew_bonus.c ft_lstsize_bonus.c
			
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
		${LIB} ${NAME} ${OBJS}
bonus: ${BONUS_OBJS}
		${LIB} ${NAME} ${BONUS_OBJS}
		${RUN} ${NAME}

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean all re
