# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 10:58:01 by midrissi          #+#    #+#              #
#    Updated: 2019/01/29 15:56:32 by midrissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf
SRCS = ft_printf.c
OBJ = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -I.
LPATH = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) lib
	@gcc $(CFLAGS) -o $(NAME) $(LPATH) $(OBJ)


$(OBJ): $(SRCS)
	@gcc $(CFLAGS) -c $(SRCS)

lib:
	@make -C ./libft

clean:
	@rm -f $(OBJ)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re lib
