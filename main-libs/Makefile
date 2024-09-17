# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 11:11:59 by trsmith           #+#    #+#              #
#    Updated: 2024/09/17 12:10:08 by trsmith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libs.a

LIBFT_DIR = ./libft/
PRINTF_DIR = ./printf/

LIBFTSRCS =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c \
			ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
			ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c \
			ft_lstsize.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
			ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c\
			ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
			ft_tolower.c ft_toupper.c ft_wordcount.c ft_atol.c ft_strcmp.c

PRINTFSRCS =ft_print_char.c\
			ft_print_numptr.c\
			ft_printnumup.c\
			ft_printnum.c\
			ft_print_str.c\
			ft_printf.c
			
LIBFT_OBJS = $(addprefix $(LIBFT_DIR)/, $(LIBFTSRCS:.c=.o))
PRINTF_OBJS = $(addprefix $(PRINTF_DIR)/, $(PRINTFSRCS:.c=.o))

OBJS = $(LIBFT_OBJS) $(PRINTFOBJS)

OBJDIR = ./objsall: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re