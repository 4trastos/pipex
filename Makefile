# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 14:19:13 by davgalle          #+#    #+#              #
#    Updated: 2024/02/28 19:44:51 by davgalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_BONUS = pipex_bonus

CC = gcc

CFLAGS = -Wall -Werror -Wextra -c -o -fsanitize=address -g3

RM = rm -f

LIB = ar rcs

SRCS = src/main.c \
	   src/pipex_aux.c \
	   src/ft_split.c \
	   src/free.c
BONUS = bonus/main.c \
		bonus/pipex_aux_bonus.c \
		bonus/ft_split.c \
		bonus/free.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c-.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) $(FLAGS) -o $(NAME_BONUS) $(BONUS_OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJS)
	$(RM) $(NAME_BONUS)
	$(RM) $(BONUS_OBJS)

re: all clean

.PHONY: all clean fclean re
