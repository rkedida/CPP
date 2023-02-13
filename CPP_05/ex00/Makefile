# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 19:23:50 by rkedida           #+#    #+#              #
#    Updated: 2023/02/13 13:43:05 by rkedida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Bureaucrat

SRC			= main.cpp Bureaucrat.cpp

HEADERS		= Bureaucrat.hpp

OBJ			= $(SRC:.cpp=.o)

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	-@$(RM) $(OBJ)

fclean: clean
	-@$(RM) $(NAME)

re: clean all

.PHONY: re, fclean, clean, all