# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/15 00:18:52 by sdarsie           #+#    #+#              #
#    Updated: 2017/06/28 21:30:16 by sdarsie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = ./libft/libft.a
LIBFTINC = -L ./libft/ -lft
INC = ft_prinft.h
INC2 = ./libft/libft.h
CFLAGS = -Wall -Wextra -Werror

LIBFT_OBJS = libft/ft_striter.o \
			 libft/ft_putnbr_fd.o \
			 libft/ft_abs_value.o \
			 libft/ft_strrev.o \
			 libft/ft_rem_ascii.o \
			libft/ft_lstmap.o \
			libft/ft_lstiter.o \
			libft/ft_lstadd.o \
			libft/ft_lstdel.o \
			libft/ft_lstdelone.o \
			libft/ft_lstnew.o \
			libft/ft_strlcat.o \
			libft/ft_itoa.o \
			libft/ft_atoi.o \
			libft/ft_strsplit.o \
			libft/ft_strtrim.o \
			libft/ft_strmapi.o \
			libft/ft_striteri.o \
			libft/ft_memcmp.o \
			libft/ft_memdel.o \
			libft/ft_memalloc.o \
			libft/ft_memchr.o \
			libft/ft_memccpy.o \
			libft/ft_memcpy.o \
			libft/ft_memmove.o \
			libft/ft_strrchr.o \
			libft/ft_strchr.o \
			libft/ft_strnstr.o \
			libft/ft_strstr.o \
			libft/ft_strjoin.o \
			libft/ft_strnew.o \
			libft/ft_strdel.o \
			libft/ft_strmap.o \
			libft/ft_strncmp.o \
			libft/ft_strcmp.o \
			libft/ft_strsub.o \
			libft/ft_putstr_fd.o \
			libft/ft_putendl_fd.o \
			libft/ft_putchar_fd.o \
			libft/ft_strnequ.o \
			libft/ft_bzero.o \
			libft/ft_isprint.o \
			libft/ft_strlen.o \
			libft/ft_putchar.o \
			libft/ft_putstr.o \
			libft/ft_isalpha.o \
			libft/ft_isdigit.o \
			libft/ft_islower.o \
			libft/ft_isupper.o \
			libft/ft_toupper.o \
			libft/ft_tolower.o \
			libft/ft_isalnum.o \
			libft/ft_isascii.o \
			libft/ft_strclr.o \
			libft/ft_strequ.o \
			libft/ft_strcpy.o \
			libft/ft_putendl.o \
			libft/ft_strdup.o \
			libft/ft_putnbr.o \
			libft/ft_strcat.o \
			libft/ft_strncpy.o \
			libft/ft_memset.o \
			libft/ft_strncat.o \
			libft/get_next_line.o \

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
		handle_hash_flag.c \
		hashing.c \

SRCS = $(addprefix $(SRC_DIR),$(FILES))

OBJ_DIR = ./obj/
OBJ_NAME = $(FILES:%.c=%.o)
OBJS = $(addprefix $(OBJ_DIR),$(OBJ_NAME))

all: obj $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	ar rc $(NAME) $(OBJS) $(LIBFT_OBJS)

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
