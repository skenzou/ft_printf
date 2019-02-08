# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 10:58:01 by midrissi          #+#    #+#              #
#    Updated: 2019/02/08 06:42:39 by midrissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c handlers.c numbers.c format_geters.c
OBJ = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -I.
LPATH = ./libft/libft.a
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@cp $(LPATH) $(NAME)
	@$(AR) $(NAME) $(OBJ)

$(OBJ): $(SRCS)
	@gcc $(CFLAGS) -c $(SRCS)

clean:
	@rm -f $(OBJ)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
d:
	@gcc main.c $(NAME) -o o
	@printf "main.c pret\n"
re: fclean all

.PHONY: all clean fclean re lib
