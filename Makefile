# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 02:22:44 by oelkhiar          #+#    #+#              #
#    Updated: 2023/07/25 02:28:19 by oelkhiar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c

OBJS = $(SRCS:.c=.o)

CC = CC

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):$(OBJS) push_swap.c
		$(CC) $(CFLAGS) $(OBJS) -o $@

CLEAN:
	@rm -f $(OBJS)

fclean:clean
		@rm -f $(NAME)

re: fclean all

.phony: re clean fclean all