NAME			= push_swap
CFLAGS			= -Wextra -Wall -Werror -Wunreachable-code
LIBFT			= ./lib/libft/
BUILD_DIR		= ./build/
SRC_DIR			= ./src/
HEADERS			= -I ./include -I $(LIBFT)/include
LIBS			= $(LIBFT)/build/libft.a
SOURCE_FILES	= main.c stack_data.c sort.c push.c swap.c rotate.c reverse_rotate.c validation.c errors.c utils.c free.c
OBJECT_FILES	= $(SOURCE_FILES:%.c=$(BUILD_DIR)%.o)

all: libft $(NAME)

libft:
	make -C $(LIBFT)

$(NAME): $(OBJECT_FILES)
	@$(CC) $(CFLAGS) $(OBJECT_FILES) $(LIBS) $(HEADERS) -o $(NAME) && printf "Compiling: $(NAME) "

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -g -o $@ -c $< $(HEADERS)

clean:
	@rm -rf $(OBJECT_FILES)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)/build

re: fclean all

.PHONY: all clean fclean re libft
