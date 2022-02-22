SRC = srcs/philosophers.c 

IFLAGS =  -I includes/
#CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror
CC = cc
OBJ = $(addprefix $(OBJS_PATH), $(SRC:.c=.o))
HEADER = includes/philosophers.h
OBJS_PATH = ./objs/
NAME = philosophers
LIB_THREAD = -lpthread

_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34mint __synthax_checker(t_lexing *lexing)

_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m
_END= $'\033[37m

all: $(NAME)

$(OBJS_PATH)%.o: %.c $(HEADER)
		mkdir -p $(dir $@)
		@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
		@printf "%-15s ${_YELLOW}${_BOLD}$<${_END}...\n" "Compiling"

$(NAME): $(OBJ) ${HEADER} ${LIBFT}
		@printf "%-15s ${_PURPLE}${_BOLD}${NAME}${_END}...\n" "Compiling"
		@$(CC) $(CFLAGS) ${OBJ} ${LIB_THREAD} -o $(NAME)
		@printf "\n${_GREEN}${_BOLD}[Compilation done !]${_END}\n"

clean:
	@printf "%-15s ${_RED}${_BOLD}${NAME}${_END}...\n" "Deleting"
	@rm -rf ${OBJS_PATH} 2> /dev/null
	@printf "%-15s ${_RED}${_BOLD}libft librairy${_END}...\n" "Deleting"
	@make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

run : $(NAME)
	valgrind --leak-check=full --track-fds=yes --show-leak-kinds=all ./philosphers

.PHONY: all clean fclean bonus re run