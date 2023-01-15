# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 02:08:05 by rkedida           #+#    #+#              #
#    Updated: 2023/01/13 02:09:23 by rkedida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= violence

SRC				= main.cpp Weaon.cpp HumanA.cpp HumanB.cpp

HEADERS			= Weapon.hpp HumanA.hpp HumanB.hpp

OBJ				= $(SRC:.cpp=.o)

CC				= c++

CFLAGS			= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: re, fclean, clean, all