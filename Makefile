# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isromero <isromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 19:25:57 by isromero          #+#    #+#              #
#    Updated: 2023/04/26 10:30:08 by isromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CC			=	gcc
SRCS		=	push_swap.c ready_stacks.c push_movements.c rotate_movements.c reverse_rotate_movements.c swap_movements.c sort_small.c sort_everything.c sort_100.c sort_500.c utils.c utils2.c

LIBFT		=	libft/libft.a

CFLAGS		=	
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)


all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C libft >/dev/null 2>&1
			@make clean -C libft >/dev/null 2>&1
			$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -o $(NAME) >/dev/null 2>&1

%o:			%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJS) >/dev/null 2>&1

fclean:		clean
			@$(RM) $(NAME) >/dev/null 2>&1
			@$(RM) *.out >/dev/null 2>&1
			@make fclean -C libft/ >/dev/null 2>&1

re:			fclean all

.PHONY:		all clean fclean re