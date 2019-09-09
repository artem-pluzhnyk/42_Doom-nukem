# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/06 12:38:04 by apluzhni          #+#    #+#              #
#    Updated: 2019/09/09 10:35:56 by apluzhni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re kill debug

NAME = doom-nukem

OPTIM = -flto -Ofast -pipe -O3 -march=native -mtune=native
DEBUG = -g -fsanitize=address
FLAGS = -Wall -Wextra -Werror $(OPTIM) $(DEBUG)

SRC_DIR = ./source/
OBJ_DIR = ./object/
INC_DIR = ./include/

SRC =	main.c						\
		\
		init/init_sdl.c				\
		init/init_data.c			\
		init/load_textures.c		\
		init/load_font.c			\
		init/load_map.c				\
		init/load_sounds.c			\
		init/default_map.c			\
		\
		settings/settings.c			\
		\
		render/frames.c				\
		render/display1.c			\
		render/display2.c			\
		render/display3.c			\
		render/additions.c			\
		render/pixels.c				\
		\
		windows/gameplay.c			\
		windows/loading_screen.c	\
		windows/menu.c				\
		windows/settings.c			\
		\
		events/events_sdl.c			\
		events/events.c				\
		\
		interface/aim.c				\
		interface/hud.c				\
		interface/gun.c				\
		\
		mapping/poster.c			\
		mapping/sprites.c

OBJ = $(addprefix $(OBJ_DIR),$(SRC:.c=.o))
INC = $(addprefix $(INC_DIR),$(addsuffix .h,doom))

LFT = -L $(LFT_DIR) -lft
LFT_DIR = ../libft/
LZIP = -L ../libzip/ -lzip
LZIP_DIR = ../libzip/
LZIP_P = ../libzip/bin/
LZIP_INC = -I ../libzip/lib/

SDL_INC =	-I ../frameworks/SDL2.framework/Headers/			\
			-I ../frameworks/SDL2_mixer.framework/Headers/	\
			-I ../frameworks/SDL2_ttf.framework/Headers/

FRAMEWORKS = -framework SDL2 -framework SDL2_mixer -framework SDL2_ttf  -F ../frameworks
SDL_PATH = -rpath @loader_path/../frameworks/

all: $(NAME)

$(NAME): lib $(OBJ_DIR) $(OBJ)
	@echo "\033[1;34m$(NAME): \033[5;36mLinking files...\033[0m"
	@gcc $(FLAGS) $(LFT) -I $(INC_DIR) -I $(LFT_DIR)/include $(SDL_INC) $(SDL_PATH) $(FRAMEWORKS) $(addprefix $(SRC_DIR),$(SRC)) -o $(NAME)
	@echo "\033[1;34m$(NAME): \033[32mComplete!\033[0m"
	@echo "\033[1;34m$(NAME): \033[32mExecutable file is ready!\033[0m"
	@echo "\033[1;33mUsage: ./$(NAME)\033[0m"

lib:
	@echo "\033[1;34m$(NAME): \033[5;36mMaking lib...\033[0m"
	@echo "\033[1;35m╔════════════════════════════════════╗\033[0m"
	@make -C $(LFT_DIR)
	@echo "\033[1;35m╚════════════════════════════════════╝\033[0m"

$(OBJ_DIR):
	@echo "\033[1;34m$(NAME): \033[5;36mCreating object folder...\033[0m"
	@mkdir $(OBJ_DIR)
	@mkdir $(OBJ_DIR)/init
	@mkdir $(OBJ_DIR)/settings
	@mkdir $(OBJ_DIR)/render
	@mkdir $(OBJ_DIR)/windows
	@mkdir $(OBJ_DIR)/events
	@mkdir $(OBJ_DIR)/interface
	@mkdir $(OBJ_DIR)/mapping
	@echo "\033[1;34m$(NAME): \033[5;36mCompiling source...\033[0m"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAGS) -I $(INC_DIR) -I $(LFT_DIR)/include $(SDL_INC) -o $@ -c $<

clean:
	@echo "\033[1;34m$(NAME): \033[5;31mCleaning lib...\033[0m"
	@echo "\033[1;35m╔════════════════════════════════════╗\033[0m"
	@make -C $(LFT_DIR) clean
	@echo "\033[1;35m╚════════════════════════════════════╝\033[0m"
	@echo "\033[1;34m$(NAME): \033[5;31mDeleting object files...\033[0m"
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;34m$(NAME): \033[5;31mDeleting debug files...\033[0m"
	@rm -rf $(NAME).dSYM
	@echo "\033[1;34m$(NAME): \033[32mCleaned!\033[0m"

fclean: clean
	@echo "\033[1;34m$(NAME): \033[5;31mDeleting lib...\033[0m"
	@echo "\033[1;35m╔════════════════════════════════════╗\033[0m"
	@make -C $(LFT_DIR) fclean
	@echo "\033[1;35m╚════════════════════════════════════╝\033[0m"
	@echo "\033[1;34m$(NAME): \033[5;31mDeleting settings...\033[0m"
	@rm -f setting.cfg
	@echo "\033[1;34m$(NAME): \033[5;31mDeleting exe file...\033[0m"
	@rm -f $(NAME)
	@echo "\033[1;34m$(NAME): \033[32mDeleted!\033[0m"

re: fclean all

kill:
	@echo "\033[1;34m$(NAME): \033[5;31mKilling proces...\033[0m"
	@pkill $(NAME)
	@echo "\033[1;34m$(NAME): \033[32mKilled!\033[0m"

debug: $(NAME)
	@echo "\033[1;34m$(NAME): \033[32mNo compile errors.\033[0m"
	@echo "\033[1;34m$(NAME): \033[5;31mDeleting map...\033[0m"
	@rm -f ./resources/maps/level0.map
	@echo "\033[1;34m$(NAME): \033[5;31mDeleting settings...\033[0m"
	@rm -f setting.cfg
	@echo "\033[1;34m$(NAME): \033[5;32mStarting Doom 2077...\033[0m"
	@./$(NAME)

git: fclean
	@git add *
	@git add .vscode
	@git commit -m "update"
	@git push
