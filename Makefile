# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 19:15:43 by mbenaoui          #+#    #+#              #
#    Updated: 2022/02/20 10:45:47 by mbenaoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC_FILE =  ft_pipex.c \
			ft_split.c \
			functions_utils.c
CC = gcc
RM = rm -f
HEADER = ft_pipex.h
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
OBJ_FILE = $(SRC_FILE:.c=.o)

all : $(NAME)

%.o:%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME) : $(OBJ_FILE)
	@echo "\033[0;34m\n\nCompiling pipex..."
	@$(CC) $(CFLAGS) $(OBJ_FILE) -o $(NAME)
	@echo $(NAME) compiled

clean :
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ_FILE) $(OBJ_FILE_BONUS)
	@echo $(NAME) object files cleaned

fclean :	clean
	@rm -f $(NAME)
	@echo $(NAME) cleaned

re : fclean all
