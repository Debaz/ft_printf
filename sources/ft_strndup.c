#include "ft_printf.h"

char			*ft_strndup(char *s, int n)
{
	char		*ret;
	int			i;

	ret = (char *)malloc(sizeof(char) * n + 1);
	if (ret && ft_strlen(s) >= n && s)
	{
		i = 0;
		while (i < n)
		{
			ret[i] = s[i];
			i++;
		}
		ret[i] = 0;
		return (ret);
	}
	return (NULL);
}
