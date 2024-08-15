# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 00:00:00 by 6:49 by tka       #+#    #+#              #
#    Updated: 2024/08/14 10:17:14 by tkartasl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

FLAGS = -Wall -Wextra -Werror -std=c++11

SRCS =	main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp	

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