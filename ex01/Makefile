# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 10:56:49 by tkartasl          #+#    #+#              #
#    Updated: 2024/07/24 15:19:32 by tkartasl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRCS = Contact.cpp \
		PhoneBook.cpp

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