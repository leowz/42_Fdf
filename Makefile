# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zweng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 18:11:43 by zweng             #+#    #+#              #
#    Updated: 2018/04/30 14:25:43 by zweng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = fdf

LIBDIR = libft

LIB = libft.a

MLXDIR = minilibx

MLXHEADERDIR = minilibx

MLXLIB = libmlx.a

SRCS = fdf.c fx_input.c fx_input_util.c fx_draw.c fx_render.c fx_transform.c \
	   fx_hook_mouse.c fx_hook_key.c fx_input_check.c\
	   ft_mlx_color.c ft_mlx_line_put.c	ft_atoi_hex.c ft_img_pixel_put.c ft_imgnew.c\

OBJS = $(patsubst %.c, %.o, $(SRCS))

HEADER_DIR = libft/includes

HEADER = fdf.h ft_mlx.h

HEADERSP = -I. -I$(HEADER_DIR) -I$(MLXHEADERDIR)

LIBSP = -L$(LIBDIR)/ -L$(MLXDIR)

LIBS = -lft -lmlx -lm

FRAMEWORK = -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
#  # ==================

all: $(NAME)

$(NAME): $(LIBDIR)/$(LIB) $(MLXDIR)/$(MLXLIB) $(OBJS)
	@$(CC) $(OBJS) $(HEADERSP) $(LIBSP) $(LIBS) $(FRAMEWORK) -o $@
	@printf $(GREEN)"  $(NAME) Finish linking\n"$(EOC)

$(LIBDIR)/$(LIB):
	@make -C $(LIBDIR)/ fclean && make -C $(LIBDIR)/

$(MLXDIR)/$(MLXLIB):
	@make -C $(MLXDIR)/ clean && make -C $(MLXDIR)/

%.o: %.c $(HEADER)
	@$(CC) -c $(CFLAGS) $(HEADERSP) $< -o $@
	@printf $(GREEN)"\r\E[K$(NAME) Finish compiling %s\n"$(EOC) $<

clean:
	@/bin/rm -f $(OBJS) 
	@printf $(GREEN)"$(NAME) clean\n"$(EOC)
	@make -C $(LIBDIR)/ clean
	@make -C $(MLXDIR)/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@printf $(GREEN)"$(NAME) fclean\n"$(EOC)
	@make -C $(LIBDIR)/ fclean

re: fclean
	@make

.PHONY: clean fclean all
