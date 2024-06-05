# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 11:43:56 by thfranco          #+#    #+#              #
#    Updated: 2024/03/19 17:43:31 by thfranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =		ft_isalpha.c			ft_isdigit.c		ft_isalnum.c	\
		ft_isascii.c			ft_isprint.c		ft_strlen.c	\
		ft_memset.c			ft_bzero.c		ft_memcpy.c	\
		ft_memmove.c			ft_strlcpy.c		ft_strlcat.c	\
		ft_toupper.c			ft_tolower.c		ft_strchr.c	\
		ft_strrchr.c			ft_strncmp.c		ft_memchr.c	\
		ft_memcmp.c			ft_strnstr.c		ft_atoi.c	\
		ft_calloc.c			ft_strdup.c		ft_substr.c	\
		ft_strjoin.c			ft_strtrim.c		ft_split.c	\
		ft_itoa.c			ft_strmapi.c		ft_striteri.c	\
		ft_putchar_fd.c			ft_putstr_fd.c		ft_putendl_fd.c	\
		ft_putnbr_fd.c			ft_count_words.c	get_next_line.c \
		get_next_line_utils.c		ft_atol.c \

BONUS = ft_lstnew_bonus.c			ft_lstadd_front_bonus.c			\
		ft_lstsize_bonus.c		ft_lstlast_bonus.c			\
		ft_lstadd_back_bonus.c		ft_lstdelone_bonus.c			\
		ft_lstclear_bonus.c		ft_lstiter_bonus.c			\
		ft_lstmap_bonus.c\


all:	$(NAME)

BONUS_OBJ = $(BONUS:.c=.o)

OBJ = $(SRCS:.c=.o)

CC		= cc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
		@ar rcs $(NAME) $(OBJ)


bonus: $(OBJ) $(BONUS_OBJ) 
		@ar rcs $(NAME) $(OBJ) $(BONUS_OBJ) 

clean:
		@$(RM) $(OBJ) $(BONUS_OBJ)

fclean:	clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY : all clean fclean re bonus
