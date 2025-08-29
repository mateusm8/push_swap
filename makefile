# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 19:02:38 by matmagal          #+#    #+#              #
#    Updated: 2025/08/29 19:35:53 by matmagal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

SRCS = 	$(SRC_DIR)/push_swap.c \
		$(SRC_DIR)/ft_lstadd_back.c \
		$(SRC_DIR)/ft_lstlast.c \
		$(SRC_DIR)/ft_lstnew.c \
		$(SRC_DIR)/ft_split.c \
		$(SRC_DIR)/ft_atol.c \
		$(SRC_DIR)/parsing.c \
		$(SRC_DIR)/swap.c \
		$(SRC_DIR)/push.c \
		$(SRC_DIR)/rotate.c \
		$(SRC_DIR)/ft_printf.c \
		$(SRC_DIR)/ft_printf_utilities.c \
		$(SRC_DIR)/reverse_rotate.c \
		$(SRC_DIR)/ft_free.c \
		$(SRC_DIR)/radix.c \
		$(SRC_DIR)/ft_lstsize.c \

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
