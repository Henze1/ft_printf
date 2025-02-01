#include "ft_printf.h"

static int	formater(va_list args, const char f);

int     ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += formater(args, s[i + 1]);
			++i;
		}
		else
			len += ft_printchar(s[i]);
		++i;
	}
	va_end(args);
	return (len);
}

static int	formater(va_list args, const char f)
{
	int	len;

	len = 0;
	switch (f)
	{
		case 'c':
			len += ft_printchar(va_arg(args, int));
			break ;
		case 's':
			len += ft_printstring(va_arg(args, char *));
			break ;
		case 'p':
			len += ft_printaddr(va_arg(args, void *));
		case 'd':
		case 'i':
		default:
			break ;
	}
	return (len);
}

int main()
{
	int len;
//	char a = 'a';
	char *s = "Hello";

	len = printf("%p\n", s);
	printf("%d\n", len);
	len = ft_printf("%p\n", s);
	printf("%d\n", len);

	return (0);
}
