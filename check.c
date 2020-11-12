#include <stdio.h>
#include "printf.h"
#include <stdlib.h>

void	ft_putnbr_base(long long int nb);

t_var *g_var = NULL;

int main(void)
{

	g_var = malloc(sizeof(t_var) + 1);
	g_var->specifier = 'X';
	printf("%#4X\n", 1);
	//printf("%lx\n", 0x7FFFFFEE);
	//ft_putnbr_base(1);
}
