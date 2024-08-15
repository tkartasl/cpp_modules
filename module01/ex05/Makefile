# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 14:26:30 by tkartasl          #+#    #+#              #
#    Updated: 2024/08/14 10:46:10 by tkartasl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harl

FLAGS = -Wall -Wextra -Werror -std=c++11

SRCS =	main.cpp \
		Harl.cpp

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