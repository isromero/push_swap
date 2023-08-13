# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isromero <isromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 19:25:57 by isromero          #+#    #+#              #
#    Updated: 2023/08/13 08:13:45 by isromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CC			=	gcc
SRCS		=	push_movements.c push_swap.c ready_stacks.c reverse_rotate_movements.c rotate_movements.c \
				sort_2_3_4.c sort_5.c sort_100.c sort_500.c sort_everything.c sort_utils.c swap_movements.c \
				utils.c utils2.c utils3.c

LIBFT		=	libft_reduced/libft.a

CFLAGS		=	-Wall -Wextra
RM			=	rm -f
OBJ_DIR		=	obj
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

all:		$(NAME)

$(NAME):	$(OBJS)
	@make -C libft_reduced >/dev/null 2>&1
	@make clean -C libft_reduced >/dev/null 2>&1
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -o $(NAME) >/dev/null 2>&1

$(OBJ_DIR)/%.o:	%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJS) >/dev/null 2>&1
	@rm -rf $(OBJ_DIR) >/dev/null 2>&1

fclean:		clean
	@$(RM) $(NAME) >/dev/null 2>&1
	@$(RM) *.out >/dev/null 2>&1
	@make fclean -C libft_reduced/ >/dev/null 2>&1

re:			fclean all

.PHONY:		all clean fclean re
