# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 09:11:35 by tkartasl          #+#    #+#              #
#    Updated: 2024/08/12 16:14:49 by tkartasl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AnimalWithBrain

FLAGS = -Wall -Wextra -Werror -std=c++11

SRCS = main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		Brain.cpp
		
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