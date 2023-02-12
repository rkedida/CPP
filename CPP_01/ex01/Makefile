# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 00:22:11 by rkedida           #+#    #+#              #
#    Updated: 2023/02/12 17:59:41 by rkedida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= zombieHorde

CC				= c++
CFLAGS			= -Wall -Wextra -Werror -std=c++98

SRC				= main.cpp Zombie.cpp zombieHorde.cpp

HEADERS			= Zombie.hpp

OBJ				= $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: re, fclean, clean, all