# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 00:00:00 by 6:49 by tka       #+#    #+#              #
#    Updated: 2024/07/29 17:44:28 by tkartasl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hordeofzombies

FLAGS = -Wall -Wextra -Werror -g -std=c++11

SRCS =	main.cpp \
		Zombie.cpp \
		zombieHorde.cpp	

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(FLAGS) -o $@ $^

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re