# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/01 15:08:34 by apluzhni          #+#    #+#              #
#    Updated: 2019/07/30 13:20:49 by apluzhni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror

SRC_DIR = ./source/
OBJ_DIR = ./object/
INC_DIR = ./include/

HEADERS = libft

FILES = 						\
		check/ft_isalnum		\
		check/ft_isalpha		\
		check/ft_isascii		\
		check/ft_isdigit		\
		check/ft_isprint		\
								\
		convert/ft_atof			\
		convert/ft_atoi			\
		convert/ft_itoa			\
		convert/ft_tolower		\
		convert/ft_toupper		\
								\
		gnl/get_next_line		\
								\
		list/ft_lstadd			\
		list/ft_lstdel			\
		list/ft_lstdelone		\
		list/ft_lstfold			\
		list/ft_lstiter			\
		list/ft_lstmap			\
		list/ft_lstnew			\
		list/ft_lstsplit		\
								\
		memory/ft_bzero			\
		memory/ft_memalloc		\
		memory/ft_memccpy		\
		memory/ft_memchr		\
		memory/ft_memcmp		\
		memory/ft_memcpy		\
		memory/ft_memdel		\
		memory/ft_memmove		\
		memory/ft_memset		\
		memory/ft_realloc		\
								\
		number/ft_nbrlen		\
								\
		other/ft_exit			\
		other/ft_swap			\
		other/ft_wordcount		\
		other/ft_wordfound		\
								\
		output/ft_putchar_fd	\
		output/ft_putchar		\
		output/ft_putendl_fd	\
		output/ft_putendl		\
		output/ft_putnbr_fd		\
		output/ft_putnbr		\
		output/ft_putstr_fd		\
		output/ft_putstr		\
								\
		string/ft_strcat		\
		string/ft_strchr		\
		string/ft_strclr		\
		string/ft_strcmp		\
		string/ft_strcpy		\
		string/ft_strdel		\
		string/ft_strdup		\
		string/ft_strequ		\
		string/ft_striter		\
		string/ft_striteri		\
		string/ft_strjoin		\
		string/ft_strlcat		\
		string/ft_strlchr		\
		string/ft_strlen		\
		string/ft_strmap		\
		string/ft_strmapi		\
		string/ft_strncat		\
		string/ft_strncmp		\
		string/ft_strncpy		\
		string/ft_strnequ		\
		string/ft_strnew		\
		string/ft_strnstr		\
		string/ft_strrchr		\
		string/ft_strsplit		\
		string/ft_strstr		\
		string/ft_strsub		\
		string/ft_strtrim

INC = $(addprefix $(INC_DIR),$(addsuffix .h,$(HEADERS)))
OBJ = $(addprefix $(OBJ_DIR),$(addsuffix .o,$(FILES)))
SRC = $(addprefix $(SRC_DIR),$(addsuffix .c,$(FILES)))

define colorecho
	  @tput setaf $2
	  @echo $1
	  @tput sgr0
endef

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(call colorecho, "║ $(NAME): Packing files...          ║", 3)
	@ar rc $(NAME) $(OBJ)
	$(call colorecho, "║ $(NAME): Building library...       ║", 3)
	@ranlib $(NAME)
	$(call colorecho, "║ $(NAME): Complete!                 ║", 2)

$(OBJ_DIR):
	$(call colorecho, "║ $(NAME): Creating object folder... ║", 3)
	@mkdir $(OBJ_DIR)
	@mkdir $(OBJ_DIR)/check
	@mkdir $(OBJ_DIR)/convert
	@mkdir $(OBJ_DIR)/gnl
	@mkdir $(OBJ_DIR)/list
	@mkdir $(OBJ_DIR)/memory
	@mkdir $(OBJ_DIR)/number
	@mkdir $(OBJ_DIR)/other
	@mkdir $(OBJ_DIR)/output
	@mkdir $(OBJ_DIR)/string
	$(call colorecho, "║ $(NAME): Compiling source...       ║", 3)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAG) -I $(INC_DIR) -o $@ -c $<

clean:
	$(call colorecho, "║ $(NAME): Deleting object files...  ║", 1)
	@rm -rf $(OBJ_DIR)

fclean: clean
	$(call colorecho, "║ $(NAME): Deleting old lib...       ║", 1)
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
