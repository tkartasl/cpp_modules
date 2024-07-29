# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 00:00:00 by 6:49 by tka       #+#    #+#              #
#    Updated: 2024/07/26 14:04:04 by tkartasl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phoneboook

SRCS = Contact.cpp \
	PhoneBook.cpp \
	main.cpp

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