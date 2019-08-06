# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/08 12:28:56 by yalytvyn          #+#    #+#              #
#    Updated: 2019/06/23 15:36:25 by ablizniu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= map_editor

NAMEDB	= map_editor_db

SRC		=	src/bind_portals_utils.c src/bind_portals.c src/data_record_sect.c \
			src/data_record_vertex.c src/declare_portal_utils.c src/declare_portal.c \
			src/display_icons.c src/display_sects.c src/display_utils.c src/edit_vertex.c \
			src/img_load.c src/img_set_poss.c src/is_inside_sect.c src/main.c src/pick_texture.c \
			src/set_points.c src/update.c src/write_map_utils.c src/write_map.c

SDL2_HEADER =	-I ./../frameworks/SDL2.framework/Headers/ \
				-I ./../frameworks/SDL2_mixer.framework/Headers/ \
				-I ./../frameworks/SDL2_ttf.framework/Headers/

SDLFLAGS = -framework SDL2 -framework SDL2_mixer -framework SDL2_ttf -F ../frameworks

OPT = -O3 -flto -pipe -Ofast -march=native -mtune=native
DB = -g

SDL2_P = -rpath @loader_path/../frameworks/

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C ../libft/
	gcc -Wall -Wextra $(OPT) -flto -pipe -Ofast -march=native -mtune=native -L ../libft/ -lft -L/usr/local/lib -I includes -I  ../libft/includes $(SDL2_HEADER) $(SDL2_P) $(SDLFLAGS) $(SRC)  -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create Editor"

obj/%.o: src/%.c
	mkdir -p obj
	gcc  -Wall -Wextra -c $(OPT) -Iincludes -I../libft/includes $(SDL2_HEADER) $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

db: $(NAMEDB)
$(NAMEDB): $(OBJ)
	make -C ../libft/
	gcc -Wall -Wextra $(DB) -L ../libft/ -lft -L/usr/local/lib -I ../includes -I ../libft/includes $(SDL2_HEADER) $(SDL2_P) $(SDLFLAGS) $(SRC)  -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create Editor"

obj/%.o: src/%.c
	mkdir -p obj
	gcc  -Wall -Wextra -c $(DB) -I includes -I ../libft/includes $(SDL2_HEADER) $< -o $@


clean:
	/bin/rm -rf obj/
	make -C ../libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ../libft/ fclean

re: fclean all

test: re
	printf '\033[32m%s\n\033[0m' "-------------------------------------"
	./doom3d

all: $(NAME)
.PHONY: clean fclean re all