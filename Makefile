SRC = sources/main.c sources/history.c
NAME = minishell
OBJ = $(SRC:.c=.o)
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror 

Reset = \033[0m
G = \033[32m
R = \033[31m
Y = \033[33m
blink = \033[6;7;1;3m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "-------------------------------------------------------------------------------------"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "-------------------------------------------------------------------------------------"
	@echo "$(blink)$(G) ✅ $(NAME) successfully compiled $(Reset)"

val:
	valgrind --leak-check=full --track-origins=yes ./minishell

hell:
	valgrind --tool=helgrind ./minishell
clean:
	$(RM) $(OBJ)
	@echo "$(Y) 😉 Objects from the $(NAME) project have been removed $(Reset)"

fclean: clean
	@echo "-------------------------------------------------------------------------------------"
	$(RM) $(NAME)
	@echo "$(blink)$(R) ❌ removed $(NAME) executable $(Reset)"
	@echo "-------------------------------------------------------------------------------------"

re: fclean all

.PHONY: all clean fclean re
