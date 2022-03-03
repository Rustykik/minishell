#include "stdio.h"
#include "libftv2test.h"

void	static_handler(void)
{
	static int	i = 0;

	printf("%d\n", i++);
}

void call_static(int i)
{
	for (int j = 0; j < i; ++j)
		static_handler();
}

int main(void)
{
	char *par = "_=";
	char *par_longer = "__CCC=30";

	char *envp_shorter = "_=abc";
	char *envp_longer = "__ABC=abc";


	char *cut_a = ft_substr(envp_shorter, 0, ft_strchr(envp_shorter, '=') - envp_shorter + 1);
	// printf("cut envp_short %s\n", cut_a);
	char *cut_b = ft_substr(envp_longer, 0, ft_strchr(envp_longer, '=') - envp_longer + 1);
	// printf("cut envp_long %s\n", cut_b);
	
	printf("[%s] [%s] %d\n", cut_a, par, ft_strncmp(cut_a, par, ft_strlen(par)));
	printf("[%s] [%s] %d\n", cut_b, par, ft_strncmp(cut_b, par, ft_strlen(par)));
	printf("[%s] [%s] %d\n", cut_a, par_longer, ft_strncmp(cut_a, par_longer, ft_strlen(par_longer)));
	printf("[%s] [%s] %d\n", cut_b, par_longer, ft_strncmp(cut_b, par_longer, ft_strlen(par_longer)));

	char *a = malloc(-5);
	perror("shelll");
}
