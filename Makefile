# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 14:19:13 by davgalle          #+#    #+#              #
#    Updated: 2024/03/02 19:08:27 by davgalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_BONUS = pipex_bonus

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

LIB = ar rcs

SRCS = src/main.c \
	   src/pipex_aux.c \
	   src/ft_split.c \
	   src/free.c
BONUS = bonus/main_bonus.c \
		bonus/pipex_aux_bonus.c \
		bonus/ft_split.c \
		bonus/free_bonus.c \
		bonus/processes_bonus.c \
		bonus/here_doc_bonus.c \
		bonus/get_next_line.c \
		bonus/get_next_line_utils.c \
		bonus/ft_inputs.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

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

re: fclean all

.PHONY: all bonus clean fclean re
