# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akrivosh <akrivosh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 17:34:39 by akrivosh          #+#    #+#              #
#    Updated: 2019/09/07 17:59:41 by akrivosh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re kill debug

NAME = map-editor

DEBUG = -g -fsanitize=address
FLAGS = -Wall -Wextra -Werror $(OPTIM) $(DEBUG)

SRC_DIR = ./source/
OBJ_DIR = ./object/
INC_DIR = ./include/
LIB_DIR = ../libft/

LIBFT = -L $(LIB_DIR) -lft

SRC =	main.c

OBJ = $(addprefix $(OBJ_DIR),$(SRC:.c=.o))
INC =	$(addprefix $(INC_DIR),$(addsuffix .h,map-editor))

SDL_INC =	-I ../frameworks/SDL2.framework/Headers/		\
			-I ../frameworks/SDL2_mixer.framework/Headers/	\
			-I ../frameworks/SDL2_ttf.framework/Headers/

FRAMEWORKS = -framework SDL2 -framework SDL2_ttf -framework SDL2_mixer -F ../frameworks
SDL_PATH = -rpath @loader_path/../frameworks/

all: $(NAME)

$(NAME): lib $(OBJ_DIR) $(OBJ)
	@echo "\033[1;34m$(NAME): \033[5;36mLinking files...\033[0m"
	@gcc $(FLAGS) $(LIBFT) -I $(INC_DIR) -I $(LIB_DIR)/include $(SDL_INC) $(SDL_PATH) $(FRAMEWORKS) $(addprefix $(SRC_DIR),$(SRC)) -o $(NAME)
	@echo "\033[1;34m$(NAME): \033[32mComplete!\033[0m"
	@echo "\033[1;34m$(NAME): \033[32mExecutable file is ready!\033[0m"
	@echo "\033[1;33mUsage: ./$(NAME)\033[0m"


lib:
	@echo "\033[1;34m$(NAME): \033[5;36mMaking lib...\033[0m"
	@echo "\033[1;35m╔════════════════════════════════════╗\033[0m"
	@make -C $(LIB_DIR)
	@echo "\033[1;35m╚════════════════════════════════════╝\033[0m"

$(OBJ_DIR):
	@echo "\033[1;34m$(NAME): \033[5;36mCreating object folder...\033[0m"
	@mkdir $(OBJ_DIR)
	@echo "\033[1;34m$(NAME): \033[5;36mCompiling source...\033[0m"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAGS) -I $(INC_DIR) -I $(LIB_DIR)/include $(SDL_INC) -o $@ -c $<

clean:
	@echo "\033[1;34m$(NAME): \033[5;31mCleaning lib...\033[0m"
	@echo "\033[1;35m╔════════════════════════════════════╗\033[0m"
	@make -C $(LIB_DIR) clean
	@echo "\033[1;35m╚════════════════════════════════════╝\033[0m"
	@echo "\033[1;34m$(NAME): \033[5;31mDeleting object files...\033[0m"
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;34m$(NAME): \033[5;31mDeleting debug files...\033[0m"
	@rm -rf $(NAME).dSYM
	@echo "\033[1;34m$(NAME): \033[32mCleaned!\033[0m"

fclean: clean
	@echo "\033[1;34m$(NAME): \033[5;31mDeleting lib...\033[0m"
	@echo "\033[1;35m╔════════════════════════════════════╗\033[0m"
	@make -C $(LIB_DIR) fclean
	@echo "\033[1;35m╚════════════════════════════════════╝\033[0m"
	@echo "\033[1;34m$(NAME): \033[5;31mDeleting settings...\033[0m"
	@rm -f setting.cfg
	@echo "\033[1;34m$(NAME): \033[5;31mDeleting exe file...\033[0m"
	@rm -f $(NAME)
	@echo "\033[1;34m$(NAME): \033[32mDeleted!\033[0m"

re: fclean all
