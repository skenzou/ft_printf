# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 10:58:01 by midrissi          #+#    #+#              #
#    Updated: 2019/02/09 02:47:33 by midrissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = srcs/ft_printf.c srcs/handlers.c srcs/numbers.c srcs/format_geters.c
OBJDIR = ./obj/
OBJ = $(patsubst srcs/%.c,$(OBJDIR)%.o,$(SRCS))
CFLAGS = -Wall -Wextra -Werror -Iincludes
LPATH = ./libft/
LIB = $(addprefix $(LPATH),libft.a)
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LPATH)
	@cp $(LIB) $(NAME)
	@$(AR) $(NAME) $(OBJ)

$(OBJ): $(SRCS)
	@gcc $(CFLAGS) -c $(SRCS)
	@mkdir $(OBJDIR)
	@mv $(notdir $(OBJ)) $(OBJDIR)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJDIR)
	@make clean -C $(LPATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LPATH)

re: fclean all

.PHONY: all clean fclean re
