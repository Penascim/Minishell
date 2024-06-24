NAME = minishell
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
LIBS = libft/libft.a

SRC = sources/main.c
OBJ = $(SRC:.c=.o)

Reset = \033[0m
G = \033[32m
R = \033[31m
Y = \033[33m
blink = \033[6;7;1;3m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "-----------------------Compilation of $(NAME)----------------------------------------"
	@make bonus -s -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS) -lreadline
	@echo "-------------------------------------------------------------------------------------"
	@echo "$(blink)$(G) ✅ $(NAME) successfully compiled $(Reset)"

val: re
	valgrind --leak-check=full --track-origins=yes --suppressions=supressions.supp -s ./minishell

clean:
	@make -s clean -C libft/
	$(RM) $(OBJ)
	@echo "$(Y) 😉 Objects from the $(NAME) project have been removed $(Reset)"

fclean: clean
	@echo "-------------------------------------------------------------------------------------"
	@make -s fclean -C libft/
	$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@echo "$(blink)$(R) ❌ removed $(NAME) executable $(Reset)"
	@echo "-------------------------------------------------------------------------------------"


re: fclean all

.PHONY: all clean fclean re
