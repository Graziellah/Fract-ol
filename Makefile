# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/12 22:31:41 by ghippoda          #+#    #+#              #
#    Updated: 2017/03/07 03:19:05 by ghippoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = ./sources/main.c ./sources/mandelbrot.c ./sources/dessin.c \
	./sources/ft_init_param.c ./sources/julia.c \
	./sources/burningship.c ./sources/circle_line.c  ./sources/init2.c\
	./sources/graz.c ./sources/mandelbrot3.c ./sources/mandelbrot5.c \
	./sources/tricorn.c ./sources/mandelbrot4.c ./sources/init3.c

FLAGS = -Wall -Wextra -Werror -Ofast

FLAGS_LBX = -lmlx -framework OpenGL -framework Appkit -L./libft -lft

OBJ = ./sources/main.o ./sources/dessin.o ./sources/mandelbrot.o\
	  ./sources/ft_init_param.o ./sources/julia.o  ./sources/init2.o\
	  ./sources/burningship.o ./sources/circle_line.o \
	  ./sources/graz.o ./sources/mandelbrot3.o ./sources/mandelbrot5.o \
	 ./sources/tricorn.o ./sources/mandelbrot4.o ./sources/init3.o

HEADER = ./includes/

LIB = libft.a

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc $(FLAGS_LBX) $(OBJ) -o $(NAME) 

%o: %c
	gcc $(FLAGS) -I$(HEADER) -o $@ -c $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libft

re: fclean all
