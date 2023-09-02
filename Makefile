# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 20:33:01 by sraza             #+#    #+#              #
#    Updated: 2023/08/30 21:43:40 by razasharuku      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
CC = cc
CFLAGS	=	-pthread -Wall -Wextra -Werror

SRCS	=	main.c \
			ft_atoi.c \
			make_philo_list.c

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