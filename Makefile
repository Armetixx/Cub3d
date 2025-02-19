# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 15:21:04 by Rigby             #+#    #+#              #
#    Updated: 2025/02/19 11:12:54 by kederhet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
INCLUDE = -I ./mlx_linux/
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -f
ECHO = echo
LIBFTNAME = libft/libft.a
LIBFTPATH = libft/
GNL = get_next_line
EXEC = exec

MLX = libmlx.a -framework OpenGL -framework AppKit

MLX_PATH = mlx_linux/
MLX_NAME = libmlx_Linux.a
MLX = $(MLX_PATH)$(MLX_NAME)

SOURCE =	main utils/str_utils errors/error map_checks/read_file $(GNL)/$(GNL) 			\
			$(GNL)/$(GNL)_utils $(EXEC)/init $(EXEC)/events $(EXEC)/map $(EXEC)/player 		\
			$(EXEC)/image $(EXEC)/draw map_checks/checkers utils/tab_utils utils/map_utils	\

SRCS = $(addsuffix .c, $(SOURCE))
OBJS = $(addsuffix .o, $(SOURCE))

GREEN = \033[0;32m
GREEN_BOLD = \033[1;32m
PINK = \033[1;35m
RED = \033[0;31m
RED_BOLD = \033[1;31m
MAGENTA = \033[0;35m
BLUE = \033[0;34m
ORANGE = \033[0;38;5;214m
YELLOW = \033[0;33m
WHITE_BG = \033[47m
CLOSE = \033[0m

LOADING_COLOR = $(RED_BOLD)

TOTAL_FILES 	:= $(words $(SOURCE))
CURRENT_FILE 	:= 0

define progress_bar
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
    @printf "\r\e[2K$(LOADING_COLOR)Compiling $(NAME)... ⌛⌛⌛	|%-0s| %d/%d " $$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "█"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then echo "\n"; fi
endef

all : $(NAME)

$(NAME) : $(LIBFTNAME) $(OBJS) $(MLX)
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFTNAME) $(INCLUDE) $(MLX) -lXext -lX11 -lm
	@$(ECHO) "                                                                                                 \n \
                                      bbbbbbbb                                           dddddddd\n \
        CCCCCCCCCCCCC                 b::::::b             333333333333333               d::::::d\n \
     CCC::::::::::::C                 b::::::b            3:::::::::::::::33             d::::::d\n \
   CC:::::::::::::::C                 b::::::b            3::::::33333::::::3            d::::::d\n \
  C:::::CCCCCCCC::::C                  b:::::b            3333333     3:::::3            d:::::d \n \
 C:::::C       CCCCCCuuuuuu    uuuuuu  b:::::bbbbbbbbb                3:::::3    ddddddddd:::::d \n \
C:::::C              u::::u    u::::u  b::::::::::::::bb              3:::::3  dd::::::::::::::d \n \
C:::::C              u::::u    u::::u  b::::::::::::::::b     33333333:::::3  d::::::::::::::::d \n \
C:::::C              u::::u    u::::u  b:::::bbbbb:::::::b    3:::::::::::3  d:::::::ddddd:::::d \n \
C:::::C              u::::u    u::::u  b:::::b    b::::::b    33333333:::::3 d::::::d    d:::::d \n \
C:::::C              u::::u    u::::u  b:::::b     b:::::b            3:::::3d:::::d     d:::::d \n \
C:::::C              u::::u    u::::u  b:::::b     b:::::b            3:::::3d:::::d     d:::::d \n \
 C:::::C       CCCCCCu:::::uuuu:::::u  b:::::b     b:::::b            3:::::3d:::::d     d:::::d \n \
  C:::::CCCCCCCC::::Cu::::::::::::::u  b:::::bbbbbb::::::b3333333     3:::::3d::::::ddddd::::::dd\n \
   CC:::::::::::::::C u::::::::::::u   b::::::::::::::::b 3::::::33333::::::3 d:::::::::::::::::d\n \
     CCC::::::::::::C  uu::::::::uu    b:::::::::::::::b  3:::::::::::::::33   d:::::::::ddd::::d\n \
        CCCCCCCCCCCCC    uuuuuuuu      bbbbbbbbbbbbbbbb    333333333333333      ddddddddd   ddddd\n \
																								 \n"

$(LIBFTNAME):
	@make -C $(LIBFTPATH)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	$(call progress_bar)

$(MLX):
	make -sC $(MLX_PATH)

clean :
	@$(RM) -r $(OBJS)
	@make clean -C $(LIBFTPATH)
	@make clean -C $(MLX_PATH)
	@$(ECHO) "[$(NAME)] obj files cleaned."


fclean : clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFTPATH)
	@make clean -C $(MLX_PATH)
	@$(ECHO) "[$(NAME)] executable removed."


re : fclean all

.PHONY : all clean fclean re