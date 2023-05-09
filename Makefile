# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 19:25:57 by isromero          #+#    #+#              #
#    Updated: 2023/05/09 08:45:48 by isromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CC			=	gcc
SRCS		=	push_swap.c ready_stacks.c push_movements.c rotate_movements.c reverse_rotate_movements.c swap_movements.c sort_small.c sort_everything.c sort_100.c sort_500.c utils.c utils2.c utils3.c

LIBFT		=	libft_reduced/libft.a

CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)


all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C libft_reduced >/dev/null 2>&1
			@make clean -C libft_reduced >/dev/null 2>&1
			$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -o $(NAME) >/dev/null 2>&1

%o:			%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJS) >/dev/null 2>&1

fclean:		clean
			@$(RM) $(NAME) >/dev/null 2>&1
			@$(RM) *.out >/dev/null 2>&1
			@make fclean -C libft_reduced/ >/dev/null 2>&1

re:			fclean all

.PHONY:		all clean fclean re