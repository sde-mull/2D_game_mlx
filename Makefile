# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 16:25:02 by pcoimbra          #+#    #+#              #
#    Updated: 2023/04/20 21:32:13 by sde-mull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

CC			=	cc
CFLAGS		=	-g  #-fsanitize=address
RM			=	rm -f
CD			=	cd

NAME		=	game
INCLUDE		=	-I ./ minilibx-linux/libmlx_Linux.a
FT_INCLUDE 	= 	-Ilibft -Llibft -lft


SRC_DIR		=	src/
SRCS		=	

GNL_DIR		=	gnl
GNL			=	$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

LIBFT		=	libft
DEPS		=	./minilibx-linux/libmlx_Linux.a

_MLX		=	./minilibx-linux
_MLX_FLAGS  =	-Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

MAP 		=

VALGRIND	= 	valgrind
VFLAGS		= 	--leak-check=full --show-leak-kinds=all

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
	@cd minilibx-linux;./configure

init: re
	./$(NAME) $(MAP)

val: re
	$(VALGRIND) $(VFLAGS) ./$(NAME) $(MAP)

clean:
	@echo	"\033[101m\033[1mObjects cleaned\033[0m"
	@$(CD) $(LIBFT) && make clean
	@$(RM) -r $(OBJDIR)/$(OBJS)
	@$(RM) -rf $(OBJDIR)
	@$(CD) $(_MLX); make clean

fclean:	clean
	@echo	"\033[101m\033[1mExecutable removed\033[0m"
	@$(CD) $(LIBFT) && make fclean
	@$(RM) -r $(NAME)
	@$(RM) -r $(_MLX)libmlx_Linux.a

re:	fclean all

.PHONY: all clean init val fclean re