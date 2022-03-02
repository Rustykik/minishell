# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 11:36:13 by rusty             #+#    #+#              #
#    Updated: 2022/03/02 14:36:33 by majacqua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

COMP = gcc -g -Wall -Werror -Wextra -fsanitize=address

LIBFT = ./src/libftv2/libft.a

ERROR_SRCS	= 	error/error_exit \
				error/error

ENV_SRCS	= 	env/set_param \
				env/get_param \
				env/del_param \
				env/env_init

PARS_SRCS	= 	parser/cut_spaces \
				parser/put_global \
				parser/parse_pipes \
				parser/parse_redir \
				parser/parse_commands

BUIL_SRCS	=	builtin/builtin \
				builtin/cd \
				builtin/echo \
				builtin/env \
				builtin/export \
				builtin/pwd \
				builtin/unset

REDIR_SRCS	= 	redirect/open_in_outs	

CMDS_SRCS	= 	commands/put_redir

SHELL_SRCS	= 	shell/init_commands \
				shell/put_redir_cmds

PIPEX_SRCS	=	pipexv2/pipex

SIG_SRCS	=	signals/signals

MAIN_SRCS = $(ERROR_SRCS)	$(ENV_SRCS)		$(PARS_SRCS)	$(SIG_SRCS) \
			$(SHELL_SRCS)	$(CMDS_SRCS)	$(REDIR_SRCS)	$(PIPEX_SRCS) \
			$(BUIL_SRCS) main

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

run: all
	./minishell

.PHONY: all clean fclean re run