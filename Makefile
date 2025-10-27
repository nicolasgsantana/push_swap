NAME = push_swap
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

LIBFT_DIR= lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)/include
LIBS = $(LIBFT)

SRC = src/main.c src/ft_atol.c src/validation.c src/utils.c src/parse.c \
src/push_op.c src/swap_op.c src/rotate_op.c src/rev_rotate_op.c \
src/sort_three.c src/sort.c src/cost.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
HEADER = inc/push_swap.h inc/validation.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
