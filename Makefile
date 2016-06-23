# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajubert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/05 14:28:27 by ajubert           #+#    #+#              #
#    Updated: 2016/06/22 17:54:16 by ajubert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		push_swap
NAME2=		checker
COMPILER=	gcc
FLAG=		-Wall -Werror -Wextra
LIB=		libft.a
INCLUDES=	-I ./libft/includes/

SRC_C=	ft_rotate_reverse.c\
		rr.c\
		ft_swap.c\
		ft_push.c\
		ft_list_push_swap.c

SRC_C1=	main.c\
		push_swap_calc.c\
		display_list.c\
		test_a.c\
		tri_a_and_b.c\
		test_swap_a.c\
		tri_small_list.c\
		tri_aa.c\
		what_ratation.c

SRC_C2=	main_checker.c

SRC_O=		$(SRC_C:.c=.o)

SRC_O1=		$(SRC_C1:.c=.o)

SRC_O2=		$(SRC_C2:.c=.o)

all: libft.a libft.h $(NAME)

$(NAME): $(SRC_O) $(SRC_O1) $(SRC_O2)
	$(COMPILER) -o $(NAME2) $(SRC_O2) $(SRC_O) $(LIB) $(FLAG)
	@echo "\033[32m=======CHECKER HAS BEEN CREATED=======\033[0m"
	$(COMPILER) -o $(NAME) $(SRC_O1) $(SRC_O) $(LIB) $(FLAG)
	@echo "\033[32m=======PUSH_SWAP HAS BEEN CREATED=======\033[0m"

%.o: %.c
	$(COMPILER) $(FLAG) -c $<

libft.a:
	@echo "\033[32m==================================="
	@echo "==========COMPILING LIBFT=========="
	@echo "===================================\033[0m"
	make re -C ./libft/
	cp ./libft/libft.a .
	make fclean -C ./libft/

libft.h:
	cp ./libft/libft/libft.h .
	cp ./libft/libft/get_next_line.h .
	cp ./libft/printf/ft_printf.h .

clean:
	@echo "\033[33m==========REMOVING OBJ FILES==========\033[0m"
	rm -rf $(SRC_O)
	rm -rf $(SRC_O1)
	rm -rf $(SRC_O2)

fclean: clean
	@echo "\033[31m==========REMOVING BIN FILES==========\033[0m"
	rm -rf $(NAME) $(NAME2) libft.a
	rm -rf libft.h
	rm -rf get_next_line.h
	rm -rf ft_printf.h

re: fclean all
