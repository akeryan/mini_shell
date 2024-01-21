# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 11:46:05 by akeryan           #+#    #+#              #
#    Updated: 2024/01/21 17:59:22 by akeryan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f

L_LINKS = -L$(READLINE_DIR)/lib -L$(LIBFT_DIR) -lreadline -lhistory -lft
I_LINKS = -I$(INCLUDE) -I$(READLINE_DIR)/include -I$(READLINE_DIR)/include/readline -I$(LIBFT_DIR)

CURRENT_DIR = $(shell pwd)
INCLUDE = include
SRC_DIR = src
READLINE_DIR = readline
LIBFT_DIR = libft
BUILD_DIR = build

MANDATORY = main.c char_itr.c node.c parser.c scanner.c

all: $(NAME)

OBJ = $(patsubst %.c, $(BUILD_DIR)/%.o, $(MANDATORY))

$(NAME): submodules readline_add libft_add $(OBJ) 
	$(CC) $(FLAGS) $(I_LINKS) -o $@ $(OBJ) $(L_LINKS)
	
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(FLAGS) $(I_LINKS) -c $< -o $@ 

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

readline_add:
	@if [ ! -d $(READLINE_DIR)/lib ]; then \
		cd $(READLINE_DIR) && ./configure --prefix=$(CURRENT_DIR)/$(READLINE_DIR); \
		make; \
		make install; \
	fi

libft_add:
	if [ ! -f $(LIBFT_DIR)/libft.a ]; then \
		make -C $(LIBFT_DIR); \
	fi

submodules:
	git submodule update
	git submodule init

clean_readline:
	@if [ -f $(READLINE_DIR)/Makefile ]; then \
		make -C $(READLINE_DIR) clean; \
	fi

fclean_readline:
	@if [ -f $(READLINE_DIR)/Makefile ]; then \
		make -C $(READLINE_DIR) uninstall; \
		make -C $(READLINE_DIR) distclean; \
	fi
	rm -rf $(READLINE_DIR)/bin
	rm -rf $(READLINE_DIR)/include
	rm -rf $(READLINE_DIR)/lib
	rm -rf $(READLINE_DIR)/share

clean: clean_readline
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)
	$(RM) -rf $(BUILD_DIR)

fclean: clean fclean_readline
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean sclean re
