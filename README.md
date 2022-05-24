# minishell
Written in C little clone of Bash.

## Implemented features of bash

executing comands  

	ba$h> ls
	Makefile  minishell  src
	ba$h> cd src
	ba$h> pwd
	/home/rusty/minishell/src
pipes `'|'`

	ba$h> cat shell/shell.h | grep int
		int				pid_c;
	int				cmds_count;
	int				cmds;
	int				exit;
	int		put_redir_cmds(t_shell *shell);
	int		init_commands(t_shell *shell, char **parsed);
	int		less_mll(const char *str);
	ba$h>

redirects `'<<'` `'>>'` `'<'` `'>'`

	ba$h> cat shell/shell.h | grep int | awk '{print $2}' >>../out.txt
	cat ../out.txt 
	pid_c;
	cmds_count;
	cmds;
	exit;
	put_redir_cmds(t_shell
	init_commands(t_shell
	less_mll(const
	ba$h>
env

	ba$h> env
	...
	LC_NUMERIC=ru_RU.UTF-8
	OLDPWD=/home/rusty
	_=./minishell
	?=0
	ba$h>
signal handling `'CTRL-C'` `'CTRL-D'` `'CTRL-\'`

	ba$h> yes
	...
	y
	y
	^C
	ba$h> echo $?
	130
	ba$h>

## How to run


tested on Ubuntu and you need to install C `readline` library

compile  

	make 

run 

	./minishell

exit

	CTRL-D on emptyline

clean 

	make fclean