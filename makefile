# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 19:02:38 by matmagal          #+#    #+#              #
#    Updated: 2025/08/26 21:27:25 by matmagal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	push_swap.c \
		ft_lstadd_back.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_split.c \
		ft_atol.c \
		parsing.c \
		swap.c \
		push.c \
		rotate.c \
		ft_printf.c \
		ft_printf_utilities.c \
		reverse_rotate.c \
		ft_free.c \
		radix.c \

OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJS)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
