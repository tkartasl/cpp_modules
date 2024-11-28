# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 10:34:01 by tkartasl          #+#    #+#              #
#    Updated: 2024/11/28 08:48:08 by tkartasl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

FLAGS = -Wall -Wextra -Werror -std=c++11

SRCS = main.cpp \
		RPN.cpp
	
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(FLAGS) $^ -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re