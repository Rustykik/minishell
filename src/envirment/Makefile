# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rusty <rusty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 11:10:24 by rusty             #+#    #+#              #
#    Updated: 2022/02/19 11:26:20 by rusty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = env.a

ENV_SRCS = 	get_env \
			put_envp \
			set_env 


ENV_SRC = $(addsuffix .c, $(ENV_SRCS))

ENV_OBJ = $(addsuffix .o, $(ENV_SRCS))

ENV_INC =	env.h

COMP = gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(ENV_OBJ)
	ar rsc $@ $^

%.o: %.c
	$(COMP) -c $< -o $@

clean:
	rm -f $(ENV_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re