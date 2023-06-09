# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 16:25:02 by pcoimbra          #+#    #+#              #
#    Updated: 2023/05/17 19:18:46 by sde-mull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

CC			=	cc
CFLAGS		=	-g  -pthread #-fsanitize=thread
RM			=	rm -f
CD			=	cd

NAME		=	game
INCLUDE		=	-I ./ minilibx-linux/libmlx_Linux.a
FT_INCLUDE 	= 	-Ilibft -Llibft -lft


SRC_DIR		=	src/
SRCS		=	game.c init_structs.c rendering.c window.c keys.c \
				save_map_information.c init_values.c images.c free.c my_mlx_func.c \
				background.c tile.c paint.c engine.c action.c check.c engine2.c \
				animation.c loading.c

GNL_DIR		=	gnl
GNL			=	$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

LIBFT		=	libft
DEPS		=	./minilibx-linux/libmlx_Linux.a

_MLX		=	./minilibx-linux
_MLX_FLAGS  =	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 

MAP 		= 	maps/map1.ber maps/map2.ber maps/map3.ber maps/map4.ber

VALGRIND	= 	valgrind
VFLAGS		= 	--leak-check=full --show-leak-kinds=all --track-origins=yes

OBJDIR		= 	obj/
OBJS		=	$(SRCS:%.c=${OBJDIR}%.o)

all:	$(NAME)

$(NAME): $(OBJS) $(DEPS) 
	@echo	"\033[102m\033[1mExecutable created\033[0m"
	@$(MAKE) -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(_MLX_FLAGS) $(GNL) $(FT_INCLUDE) -o $(NAME) $(INCLUDE) -L $(_MLX)

$(OBJDIR)%.o:$(SRC_DIR)%.c
	mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@


$(DEPS):
	@cd minilibx-linux;./configure > /dev/null 2>&1
init: re
	./$(NAME) $(MAP)

val: re
	$(VALGRIND) $(VFLAGS) ./$(NAME) $(MAP)

clean:
	@echo	"\033[101m\033[1mObjects cleaned\033[0m"
	@$(CD) $(LIBFT) && make clean
	@$(RM) -r $(OBJDIR)/$(OBJS)
	@$(RM) -rf $(OBJDIR)
	@$(CD) $(_MLX); make clean > /dev/null

fclean:	clean
	@echo	"\033[101m\033[1mExecutable removed\033[0m"
	@$(CD) $(LIBFT) && make fclean
	@$(RM) -r $(NAME)
	@$(RM) -r $(_MLX)libmlx_Linux.a

re:	fclean all

.PHONY: all clean init val fclean re