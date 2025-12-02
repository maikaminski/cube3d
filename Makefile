NAME = cub3D

# Directories
SRC_DIR = src
INC_DIR = includes
LFT_DIR = libft
MLX_DIR = minilibx-linux

# Source files
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/parsing/file_parser.c \
       $(SRC_DIR)/parsing/map_parser.c \
       $(SRC_DIR)/parsing/texture_parser.c \
       $(SRC_DIR)/parsing/validation.c \
       $(SRC_DIR)/raycasting/raycasting.c \
       $(SRC_DIR)/raycasting/dda.c \
       $(SRC_DIR)/graphics/renderer.c \
       $(SRC_DIR)/graphics/textures.c \
       $(SRC_DIR)/graphics/image.c \
       $(SRC_DIR)/player/movement.c \
       $(SRC_DIR)/player/collision.c \
       $(SRC_DIR)/utils/cleanup.c \
       $(SRC_DIR)/utils/error.c \
       $(SRC_DIR)/utils/math_utils.c

# Object files
OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -no-pie
INCLUDES = -I$(INC_DIR) -I$(LFT_DIR) -I$(MLX_DIR)
LIBS = -L$(LFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Colors
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(LDFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compiled successfully!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make clean -C $(LFT_DIR)
	@make clean -C $(MLX_DIR)
	@echo "$(RED)🧹 Object files cleaned$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LFT_DIR)
	@echo "$(RED)🗑️  Executable removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re