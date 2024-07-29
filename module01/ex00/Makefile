# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 00:00:00 by 6:49 by tka       #+#    #+#              #
#    Updated: 2024/07/29 14:17:52 by tkartasl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

SRCS =	main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp		

CPP_FLAGS = c++ -Wall -Wextra -Werror -std=c++11

%.o: %.cpp

all: ${NAME}

${NAME}: ${OBJS}

${OBJS}: ${SRCS}
	${CPP_FLAGS} -c ${SRCS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all%        