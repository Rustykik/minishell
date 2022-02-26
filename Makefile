# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rusty <rusty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 11:36:13 by rusty             #+#    #+#              #
#    Updated: 2022/02/26 22:05:12 by rusty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

COMP = gcc -g -Wall -Werror -Wextra -fsanitize=address

LIBFT = ./src/libftv2/libft.a

ENV_SRCS = 	env/get_env \
			env/put_envp \
			env/set_env 

PARS_SRCS = parser/cut_spaces \
			parser/put_global \
			parser/parse_pipes \
			parser/parse_redir \
			parser/parse_commands

REDIR_SRCS = 	redirect/open_in_outs	

CMDS_SRCS = 	commands/put_redir

SHELL_SRCS = 	shell/init_commands \
				shell/put_redir_cmds

MAIN_SRCS = $(ENV_SRCS)		$(PARS_SRCS) \
			$(SHELL_SRCS)	$(CMDS_SRCS) $(REDIR_SRCS) main

MAIN_SRC = $(addprefix ./src/, $(addsuffix .c, $(MAIN_SRCS)))

MAIN_OBJ = $(addprefix ./src/, $(addsuffix .o, $(MAIN_SRCS)))

all: $(NAME)

$(NAME): $(LIBFT) $(MAIN_OBJ)
	$(COMP) $(MAIN_OBJ) $(LIBFT) -o $@ -lreadline

%.o: %.c Makefile $(LIBFT)
	$(COMP) -c $< -o $@ -I./src/env/ -I./src/libftv2/libft/ 

$(LIBFT): ./src/libftv2/ft_zalloc/*.c ./src/libftv2/ft_zalloc/*.h ./src/libftv2/libft/*.c ./src/libftv2/libft/*.h ./src/libftv2/Makefile ./src/libftv2/libftv2.h
	make -C ./src/libftv2/

clean:
	rm -f $(MAIN_OBJ)
	make -C ./src/libftv2 fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re