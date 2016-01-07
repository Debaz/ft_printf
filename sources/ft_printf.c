#include "ft_printf.h"
#include <unistd.h>

int					check_flag(char c)
{
	int				i;

	i = 0;
	while (FLAGS[i])
	{
		if (FLAGS[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int			print_flag(char *f)
{
	int				i;
	
	write(1, "[", 1);
	i = 0;
	while (check_flag(f[i]))
	{
		write(1, &f[i], 1);
		i++;
	}
	write(1, "]\n", 2);
	return (i);
}

static char			*next_content(char *s)
{
	size_t			i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			return (ft_strndup(s, i));
		i++;
	}
	return (s);
}

int					ft_printf(char *fmt, ...)
{
	char			*result;
	va_list			ap;
	int				len;
	int				fmt_len;

	(void)ap;
	len = 0;
	while (ft_strlen(fmt) > 0)
	{
		if (fmt[0] == '%')
		{
			fmt_len = print_flag(&fmt[1]);
			fmt = &fmt[fmt_len + 1];
		}
		result = next_content(fmt);
		len += write(1, result, ft_strlen(result));
		fmt = &(fmt[ft_strlen(result)]);
	}
	return (len);
}
