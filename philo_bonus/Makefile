# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 22:37:40 by ressalhi          #+#    #+#              #
#    Updated: 2022/05/24 14:11:37 by ressalhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = philo_bonus.c philo_routine_bonus.c philo_utils_bonus.c init_parse_bonus.c

all : $(NAME)

$(NAME) : 
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all

.PHONY : all clean fclean re
