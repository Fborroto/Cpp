# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 15:37:25 by fborroto          #+#    #+#              #
#    Updated: 2023/11/28 15:39:58 by fborroto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  Phonebook

SRC =   *.cpp

OBJ =   *.o

CFLAGS =  -Wall -Wextra -Werror

RM  =  rm -rf

GG = g++ -std=c++98

NONE="\033[0n"
GREEN="\033[32m"
GRAY="\033[2;37m"
CURSIVE="\033[3m"

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE) $(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@$(GG) $(FLAGS) $(OBJ) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm -rf $(OBJ)

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@$(GG) -c $(SRC)


run:
	./$(NAME)

clean: 
	$(RM) .o

fclean:
	$(RM) .o
	$(RM) $(NAME)

re:	fclean all