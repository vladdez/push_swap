# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 12:05:29 by kysgramo          #+#    #+#              #
#    Updated: 2020/02/16 12:05:33 by kysgramo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



PUSH_SWAP = push_swap

CHECKER = checker

FLAGS = -Wall -Wextra -Werror -I. -I ./libft/libft -I ./libft/printf

LIB = -L libft/ -lft

PUSH_SWAP_SRC_DIR= src_push_swap/

CHECKER_SRC_DIR= src_checker/

HEADER= push_swap.h

CPUSH_SWAP = small.c get_next_line.c comb_lock_finder.c comb_lock_stat.c circular_lock.c p_printer.c simple_sorts.c \
hard_sort_part.c hard_sorts.c cmds.c list.c list2.c c_handler.c p_finders.c push_swap.c p_pivots.c viz.c usecmd.c create_struct.c
CCHECKER = small.c checker.c get_next_line.c comb_lock_finder.c comb_lock_stat.c circular_lock.c p_printer.c simple_sorts.c \
hard_sort_part.c hard_sorts.c cmds.c list.c list2.c c_handler.c p_finders.c p_pivots.c viz.c usecmd.c create_struct.c

PUSH_SWAP_SRC = $(addprefix $(PUSH_SWAP_SRC_DIR),$(CPUSH_SWAP))

CHECKER_SRC = $(addprefix $(CHECKER_SRC_DIR),$(CCHECKER))

PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:%.c=%.o)

CHECKER_OBJ = $(CHECKER_SRC:%.c=%.o)

.PHONY: all clean fclean re

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(PUSH_SWAP_OBJ) $(HEADER)
	make -C libft
	gcc $(FLAGS) $(PUSH_SWAP_OBJ) -o $(PUSH_SWAP) $(LIB)

$(PUSH_SWAP_SRC_DIR)%.o : $(PUSH_SWAP_SRC_DIR)%.c $(HEADER)
	gcc -c $(FLAGS) $< -o $@

$(CHECKER): $(CHECKER_OBJ) $(HEADER)
	make -C libft
	gcc $(FLAGS) $(CHECKER_OBJ) -o $(CHECKER) $(LIB)

$(CHECKER_SRC_DIR)%.o : $(CHECKER_SRC_DIR)%.c $(HEADER)
	gcc -c $(FLAGS) $< -o $@

clean:	
	@rm -f $(CHECKER_OBJ)
	@rm -f $(PUSH_SWAP_OBJ)

fclean: clean	
	make fclean -C libft/	
	rm -fv $(PUSH_SWAP) $(CHECKER)

re: fclean all