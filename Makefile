# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 20:33:01 by sraza             #+#    #+#              #
#    Updated: 2023/09/02 20:04:32 by sraza            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
CC = cc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	main.c \
			ft_atoi.c \
			make_philo_list.c \
			initialize.c \
			x

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