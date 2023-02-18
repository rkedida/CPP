# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 19:23:50 by rkedida           #+#    #+#              #
#    Updated: 2023/02/18 12:37:11 by rkedida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Intern

SRC			= main.cpp AForm.cpp Bureaucrat.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp

HEADERS		= AForm.hpp Bureaucrat.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp

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