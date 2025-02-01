#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *s, ...);
int	ft_printchar(unsigned char c);
int     ft_printstring(char *str);
int	ft_printaddr(void *p);

#endif
