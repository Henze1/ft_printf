#include "ft_printf.h"

int	ft_printstring(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_printchar(str[i]);
		++i;
	}
	return (i);
}
