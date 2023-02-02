# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 12:21:43 by rkedida           #+#    #+#              #
#    Updated: 2023/01/22 12:23:54 by rkedida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Fixed

SRC			= main.cpp Fixed.cpp

HEADERS		= Fixed.hpp

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