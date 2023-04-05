# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isromero <isromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 19:25:57 by isromero          #+#    #+#              #
#    Updated: 2023/04/04 21:35:40 by isromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CC			=	gcc
SRCS		=	push_swap.c check.c ready_stacks.c movements.c small_numbers.c sort_numbers.c utils.c
SRCS_BONUS	=	

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