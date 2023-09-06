# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 20:33:01 by sraza             #+#    #+#              #
#    Updated: 2023/09/06 14:23:24 by razasharuku      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
CC = cc
CFLAGS	=	-pthread -Wall -Wextra -Werror -g -fsanitize=address

SRCS	=	main.c \
			ft_atoi.c \
			make_philo_list.c \
			initialize.c \
			create_threads.c \
			conditions.c \
			free.c \
			routine.c \
			print_condition.c \

OBJS = ${SRCS:%.c=%.o}

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re