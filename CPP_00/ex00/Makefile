# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/31 15:17:41 by rkedida           #+#    #+#              #
#    Updated: 2023/02/12 18:00:50 by rkedida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		megaphone

SRC		=		megaphone.cpp

OBJ		=		$(SRC:.cpp=.o)

CC		=		c++
CFLAGS	=		-Wall -Wextra -Werror -std=c++98 

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	-@$(RM) $(OBJ)

fclean: clean
	-@$(RM) $(NAME)

re: clean all

.PHONY: re, fclean, clean, all