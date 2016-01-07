#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

# define FLAGS "hljz"

int					ft_printf(char *fmt, ...);
int					ft_strlen(char const *s);
char				*ft_strndup(char *s, int n);

#endif
