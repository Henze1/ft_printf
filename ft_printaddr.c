#include "ft_printf.h"

static int	write_hex(void *p);

int	ft_printaddr(void *p)
{
	int		len;

	len = 0;
	len += ft_printchar('0');
	len += ft_printchar('x');
	len += write_hex(p);
	return (len);
}

static int	write_hex(void *p)
{
	int		i;
	int		len;
	long long	ptr;
	char		numarr[16];

	i = 0;
	len = 0;
	ptr = (long long)p;
	while (ptr)
	{
		if (ptr % 16 >= 10)
			numarr[i++] = ptr % 16 - 10 + 'a';
		else
			numarr[i++] = ptr % 16 + '0';
		++len;
		ptr /= 16;
	}
	while (i--)
		ft_printchar(numarr[i]);
	return (len);
}
