# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 14:52:00 by tkartasl          #+#    #+#              #
#    Updated: 2024/08/14 10:36:58 by tkartasl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sedIsForLosers

FLAGS = -Wall -Wextra -Werror -std=c++11

SRCS =	main.cpp

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