GREEN  = \033[1;32m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
CYAN   = \033[1;36m
RESET  = \033[0m
ERASE  = \033[K

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

SRC = src/push_swap.c src/ft_atol.c src/validation.c src/utils.c \
src/parse.c src/push_op.c src/swap_op.c src/rotate_op.c \
src/rev_rotate_op.c src/sort_three.c src/sort.c src/cost.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
HEADER = inc/push_swap.h inc/validation.h

BONUS = checker
SRC_BONUS = src/checker_bonus.c src/validation.c src/parse.c \
src/push_op.c src/rotate_op.c src/rev_rotate_op.c src/swap_op.c \
src/sort_three.c src/utils.c src/ft_atol.c src/input_read_bonus.c \
src/op_exec_bonus.c
HEADER_BONUS = inc/checker_bonus.h

OBJ_BONUS = $(SRC_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@printf "\n$(GREEN)$(NAME) created$(RESET)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "\r$(ERASE)$(BLUE) compiled $(notdir $@)$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@printf "$(GREEN)dir $(OBJ_DIR)/ created $(RESET)\n"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(BONUS): $(LIBFT) $(OBJ_BONUS) $(HEADER_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBS) -o $(BONUS)
	@printf "\n$(GREEN)$(BONUS) created$(RESET)\n"

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@printf "$(YELLOW)removed $(OBJ_DIR)/ dir$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(YELLOW)removed $(NAME)$(RESET)\n"
	@rm -f $(BONUS)
	@printf "$(YELLOW)removed $(BONUS)$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
