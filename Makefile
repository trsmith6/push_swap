# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 09:34:35 by trsmith           #+#    #+#              #
#    Updated: 2024/09/23 12:35:58 by trsmith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	push_swap.c \
		utils.c \
		push_revrot.c \
		rotate.c \
		sort_index.c \
		checks.c \
		swap.c \
		utils2.c \
		utils3.c \
		
COMPILER = cc

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

init:
	@git submodule init && git submodule update && cd main-libs && git submodule init && git submodule update

$(NAME): $(OBJS)
	@cd main-libs && make --silent
	@$(COMPILER) $(CFLAGS) -o $(NAME) $(OBJS) ./main-libs/libs.a
clean:
	@cd main-libs && make fclean
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re