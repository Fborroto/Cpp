# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 14:45:47 by fborroto          #+#    #+#              #
#    Updated: 2023/11/28 14:45:47 by fborroto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  Megaphone

SRC =   Megaphone.cpp

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



leaks: all
	@echo "     - Executing $(NAME) with leaks command..."
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "shhhhh... I think the students are asleep..."
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) " ! " "Sorry students, I thought this thing was off."
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
	@echo "     - Done -"

test: all
	./$(NAME) "shhhhh... I think the students are asleep..."
	./$(NAME) " ! " "Sorry students, I thought this thing was off."
	./$(NAME)

clean: 
	$(RM) .o

fclean:
	$(RM) .o
	$(RM) $(NAME)