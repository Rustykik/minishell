#include "stdio.h"

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
	call_static(2);
	call_static(3);
}