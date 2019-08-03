# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/06 12:38:04 by apluzhni          #+#    #+#              #
#    Updated: 2019/08/03 15:23:31 by apluzhni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re kill start restart

NAME = doom-nukem

OPTIM = -flto -Ofast -pipe -O2
DEBUG = -g -fsanitize=address
FLAGS = -Wall -Wextra -Werror $(OPTIM) $(DEBUG)

LIBFT_LNK = -L ./libft/ -lft

BREW = /Users/apluzhni/.brew/Cellar
SDL_INC = -I $(BREW)/sdl2/2.0.9_1/include/SDL2 \
	-I $(BREW)/sdl2_image/2.0.4/include/SDL2 \
	-I $(BREW)/sdl2_ttf/2.0.15/include/SDL2 \
	-I $(BREW)/glfw/3.3/include/GLFW
SDL_LIB = -L $(BREW)/sdl2/2.0.9_1/lib/ -l SDL2-2.0.0 \
	-L $(BREW)/sdl2_image/2.0.4/lib/ -l SDL2_image-2.0.0 \
	-L $(BREW)/sdl2_ttf/2.0.15/lib/ -l SDL2_ttf-2.0.0 \
	-L $(BREW)/glfw/3.3/lib/ -l glfw.3.3

FMWK = $(SDL_INC) $(SDL_LIB)

SRC_DIR = ./source/
OBJ_DIR = ./object/
INC_DIR = ./include/
LIB_DIR = ./libft/

SRC = main.c						\
	initialization/settings.c		\
	initialization/initialization.c	\
	initialization/load_resources.c	\
	initialization/scan_map.c		\
	initialization/default_map.c	\
	\
	render/frames.c					\
	render/pixels.c					\
	render/display1.c				\
	render/display2.c				\
	render/display3.c				\
	render/options.c				\
	\
	events/events_sdl.c				\
	events/moves.c					\
	events/mouse.c					\
	\
	window/loading_screen.c			\
	window/menu.c					\
	window/gameplay.c				\
	window/settings.c				\
	\
	interface/aim.c					\
	interface/hud.c					\
	\
	map_editor/map_editor.c

OBJ = $(addprefix $(OBJ_DIR),$(SRC:.c=.o))
INC = $(addprefix $(INC_DIR),$(addsuffix .h,$(NAME)))

all: $(NAME)

$(NAME): lib $(OBJ_DIR) $(OBJ)
	@echo "\033[1;34m$(NAME): \033[5;36mLinking files...\033[0m"
	@gcc $(FLAGS) $(LIBFT_LNK) $(FMWK) -I $(INC_DIR) $(addprefix $(SRC_DIR),$(SRC)) -o $(NAME)
	@echo "\033[1;34m$(NAME): \033[32mComplete!\033[0m"
	@echo "\033[1;34m$(NAME): \033[32mExecutable file is ready!\033[0m"
	@echo "\033[1;33mUsage: ./$(NAME)\033[0m"

lib:
	@echo "\033[1;34m$(NAME): \033[5;36mMaking lib...\033[0m"
	@echo "\033[1;35m╔════════════════════════════════════╗\033[0m"
	@make -C ./libft/
	@echo "\033[1;35m╚════════════════════════════════════╝\033[0m"

$(OBJ_DIR):
	@echo "\033[1;34m$(NAME): \033[5;36mCreating object folder...\033[0m"
	@mkdir $(OBJ_DIR)
	@mkdir $(OBJ_DIR)\initialization
	@mkdir $(OBJ_DIR)\render
	@mkdir $(OBJ_DIR)\events
	@mkdir $(OBJ_DIR)\window
	@mkdir $(OBJ_DIR)\interface
	@mkdir $(OBJ_DIR)\map_editor
	@echo "\033[1;34m$(NAME): \033[5;36mCompiling source...\033[0m"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAGS) -I $(INC_DIR) $(SDL_INC) -o $@ -c $<

clean:
	@echo "\033[1;34m$(NAME): \033[5;31mCleaning lib...\033[0m"
	@echo "\033[1;35m╔════════════════════════════════════╗\033[0m"
	@make -C ./libft/ clean
	@echo "\033[1;35m╚════════════════════════════════════╝\033[0m"
	@echo "\033[1;34m$(NAME): \033[5;31mDeleting object files...\033[0m"
	@rm -rf $(OBJ_DIR)
	@rm -rf doom.dSYM
	@echo "\033[1;34m$(NAME): \033[32mCleaned!\033[0m"

fclean: clean
	@echo "\033[1;34m$(NAME): \033[5;31mDeleting lib...\033[0m"
	@echo "\033[1;35m╔════════════════════════════════════╗\033[0m"
	@make -C ./libft/ fclean
	@echo "\033[1;35m╚════════════════════════════════════╝\033[0m"
	@echo "\033[1;34m$(NAME): \033[5;31mDeleting exe file...\033[0m"
	@rm -f $(NAME)
	@rm -f setting.cfg
	@rm -rf $(NAME).dSYM
	@rm -rf .vscode
	@echo "\033[1;34m$(NAME): \033[32mDeleted!\033[0m"

re: fclean all

kill:
	@echo "\033[1;34m$(NAME): \033[5;31mKilling proces...\033[0m"
	@pkill $(NAME)
	@echo "\033[1;34m$(NAME): \033[32mKilled!\033[0m"

start: $(NAME)
	@echo "\033[1;34m$(NAME): \033[32mNo compile errors.\033[0m"
	@echo "\033[1;34m$(NAME): \033[5;32mStarting Doom 2077...\033[0m"
	@rm -f resource/maps/buffer.map
	@./doom-nukem
