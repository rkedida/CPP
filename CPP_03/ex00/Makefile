# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 11:36:51 by rkedida           #+#    #+#              #
#    Updated: 2023/02/03 11:43:08 by rkedida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ClapTrap

SRC			= main.cpp ClapTrap.cpp

HEADERS		= ClapTrap.hpp

OBJ			= $(SRC:.cpp=.o)

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	-@$(RM) $(OBJ)

fclean: clean
	-@$(RM) $(NAME)

re: clean all

.PHONY: re, fclean, clean, all