# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 13:44:49 by ksoulard          #+#    #+#              #
#    Updated: 2016/08/17 16:18:11 by klescaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		ft_printf

CC =		gcc

EXT =		.c

FLAGS =		-Wall -Wextra -Werror -g

FILE =		maintest ft_printf_main conv_1 tools_1

SOURCE = 	sources/

INCLUDE =	includes/

HEADER = 	ft_printf.h libft.h

FILES =		$(addprefix $(SOURCE), $(addsuffix $(EXT), $(FILE)))

OBJ =		$(FILES:$(EXT)=.o)

LIB_DIR =	sources/libft

EXEC=		$(LIB_DIR)/$(LIB_DIR).a

C_W=		\033[0m
C_R=		\033[38;5;124m
C_Y=		\033[38;5;214m
C_B=		\033[38;5;97m
C_N=		\033[38;5;200m
C_G=		\033[38;5;190m

all: 	 $(NAME) #norme

$(NAME): $(OBJ)
		@$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L./sources/libft -lft
		@echo "\n$(C_Y)$(NAME) $(C_R)		is done !$(C_W)"

%.o:	%$(EXT) $(INCLUDE)
		@$(CC) $(FLAGS) -c $< -o $@ -I./includes
		@printf "\033[32m.$(C_W)"

clean:
		@rm -rf $(OBJ)
		@echo "$(C_B)$(NAME)$(C_R)		All obj are cleaned$(C_W)"

fclean: clean
		@rm -rf $(NAME)
		@echo "\n$(C_G)$(NAME)$(C_R)		is clean$(C_W)"

norme:
		@echo "\nSource:$(C_N)"
		@norminette $(FILES)
		@echo "\n$(C_W)Header:$(C_N)"
		@norminette $(INCLUDE)$(HEADER)
		@echo "$(C_W)"

re: fclean all
