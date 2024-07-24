# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 10:56:49 by tkartasl          #+#    #+#              #
#    Updated: 2024/07/24 11:42:57 by tkartasl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRCS = megaphone.cpp

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