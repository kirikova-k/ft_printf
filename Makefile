# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 15:12:51 by ogarthar          #+#    #+#              #
#    Updated: 2021/10/18 15:16:37 by ogarthar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# usage:	-make
# 			-main in ft_printf
# 			-make x

NAME = libftprintf.a

LIST =		ft_printf.c				ft_process_flags.c\
			spec_int.c				spec_uint.c				spec_c_str_percent.c\
			spec_hex.c				spec_pointer.c\
			ft_ultoa_base.c			ft_strdup.c				ft_strlen.c\
			ft_strchr.c				ft_put_char_str_n.c

LIST_B =	ft_printf.c				ft_process_flags.c\
			spec_int.c				spec_uint.c				spec_c_str_percent.c\
			spec_hex.c				spec_pointer.c\
			ft_ultoa_base.c			ft_strdup.c				ft_strlen.c\
			ft_strchr.c				ft_put_char_str_n.c

VPATH = src:

OBJ = $(patsubst %.c,%.o,$(LIST))
OBJ_B = $(patsubst %.c,%.o,$(LIST_B))

FLAGS = -Wall -Werror -Wextra -I./

all : $(NAME)

$(NAME) : $(OBJ) ft_printf.h Makefile
	ar rcs $(NAME) $?

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

bonus : $(OBJ_B)
	ar rcs $(NAME) $?

clean :
	@rm -f $(OBJ) $(OBJ_B)

fclean : clean
	@rm -f $(NAME)

re : fclean all

x: all
	gcc ft_printf.c libftprintf.a
	./a.out

.PHONY : all clean fclean re bonus
