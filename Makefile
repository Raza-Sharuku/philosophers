# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 20:33:01 by sraza             #+#    #+#              #
#    Updated: 2023/09/13 20:04:26 by sraza            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
CC = cc
CFLAGS	=	-pthread -Wall -Wextra -Werror -g -fsanitize=thread 
# -g -fsanitize=address

SRCS	=	main.c \
			ft_atoi.c \
			ft_isalpha.c \
			make_philo_list.c \
			initialize.c \
			create_threads.c \
			conditions.c \
			free.c \
			routine.c \
			print_condition.c \
			mutex_destory.c \

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