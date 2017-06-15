# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/15 00:18:52 by sdarsie           #+#    #+#              #
#    Updated: 2017/06/15 00:18:56 by sdarsie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = ./libft/libft.a
LIBFTINC = -L ./libft/ -lft
INC = ft_prinft.h
INC2 = ./libft/libft.h
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/
FILES = ft_printf.c \
		ft_itoa_base.c \
		ft_uitoa_base.c \
		big_itoa_base.c \
		maths.c \
		specifics.c \
		flag_handleing.c \
		apply_flags.c \
		extra.c \
		handle_specs.c \
		try_length.c \
		print_ints.c \
		print_hex.c \
		more_hex_printing.c \
		more_dispatching.c \
		print_memory_addrs.c \

SRCS = $(addprefix $(SRC_DIR),$(FILES))

OBJ_DIR = ./obj/
OBJ_NAME = $(FILES:%.c=%.o)
OBJS = $(addprefix $(OBJ_DIR),$(OBJ_NAME))

all: obj $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	ar rc $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc $(CFLAGS) -o $@ -c $<

obj:
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C ./libft

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft

fclean: clean
	@make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: clean all
