# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 00:00:00 by 6:49 by tka       #+#    #+#              #
#    Updated: 2024/07/25 13:13:25 by tkartasl         ###   ########.fr        #
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