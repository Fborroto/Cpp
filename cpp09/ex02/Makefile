# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 16:59:50 by fborroto          #+#    #+#              #
#    Updated: 2025/01/06 15:32:26 by fborroto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= PmergeMe

CC			= c++ -std=c++98
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

OBJDIR      = .objFiles

FILES		= main  PmergeMe

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= PmergeMe.hpp

NONE="\033[0m"
GREEN="\033[32m"
GRAY="\033[2;37m"
CURSIVE="\033[3m"
YELLOW=	"\033[1;33"

.PHONY: all clean fclean re leaks

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@echo $(CURSIVE) $(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@$(CC)  $(FLAGS) $(OBJ) $(OPTS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(OPTS) -c $< -o $@

compile_and_run: re
	@./$(NAME)

run:
	@./$(NAME)

numbers:
	@./$(NAME) `shuf -i 1-1000 -n 1000 | tr "\n" " "` > outfile.txt

leaks:
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

clean:
	@$(RM) $(OBJDIR) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all