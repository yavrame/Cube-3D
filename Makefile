NAME = cub3D

SRCS_DIR = srcs
OBJS_DIR = objs

SRCS_MF = 	main.c utils.c\
			parsing.c parse_identifiers.c parse_colors.c\
			parse_map.c check_map.c\
			clear.c\
			mlx.c render.c\
			raycasting.c\
			draw_elements.c textures.c\
			draw.c keys.c\
			move.c rotate.c\
			minimap.c

OBJS_M = $(addprefix $(OBJS_DIR)/, $(patsubst %.c,%.o, $(SRCS_MF)))
D_FILES_M = $(addprefix $(OBJS_DIR)/, $(patsubst %.c,%.d, $(SRCS_MF)))

detected_OS := $(shell uname)

ifeq ($(detected_OS), Darwin)
	INCLUDES = -I./includes/ -I ./mlx -I libft/includes/
	MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
	MLX_FOLDER = ./mlx
	ADD_DEF = -D DARWIN_KEYS
else
	INCLUDES = -I./includes/  -I ./mlx_linux -I./libft/includes/
	MLX = -Lmlx_linux -lmlx_Linux -lm -lz -lX11 -lXext
	MLX_FOLDER = ./mlx_linux
	ADD_DEF = -D LINUX_KEYS -DESC=6537 -DW=119 -DS=115 -DA=97 -DD=100 -DLEFT=65361 -DRIGHT=65363 -DPLUS=65451 -DMIN=65453
endif

LIBFT = ./libft/libft.a
LIB_INC = -L./libft/ -lft

#colors
RED 	= 	\033[0;31m
GREEN 	= 	\033[0;32m
BLUE	=	\033[0;34m
BREAK 	= 	\033[0m
YELLOW	=	\033[0;33m

OPFLAGS = -O2
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
SANIT_FLAGS = cc -fsanitize=address $(CFLAGS)

.PHONY : all lib clean fclean sanit_m re

all : lib $(NAME)

$(OBJS_DIR) :
	mkdir $@

lib :
	make -C libft/

$(NAME) : $(OBJS_M) $(LIBFT)
	make -C $(MLX_FOLDER)
	$(CC) $(CFLAGS) $(OPFLAGS) $(OBJS_M) $(LIB_INC) $(MLX) -o $(NAME)
	@echo "$(BLUE)$(NAME)$(GREEN) --> DONE!$(BREAK)"

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(OPFLAGS) $(INCLUDES) $(ADD_DEF) -c $< -o $@ -MD

clean :
	make -C libft/ $@
	make -C $(MLX_FOLDER) $@
	rm -rf $(OBJS_DIR)
	@echo "$(BLUE)objs $(RED)--> DELETED$(BREAK)"

fclean : clean
	make -C libft/ $@
	@echo "$(BLUE)libft.a $(RED)--> DELETED$(BREAK)"
	rm -f $(NAME)
	@echo "$(BLUE)$(NAME) $(RED)--> DELETED$(BREAK)"

re : fclean all

re_cub3d : 
	rm -rf $(OBJS_DIR)
	@echo "$(BLUE)objs $(RED)--> DELETED$(BREAK)"
	make all

sanit_m :
	make
	$(SANIT_FLAGS) $(OBJS_M) $(LIB_INC) $(MLX) -o $(NAME)

-include $(D_FILES_M)
