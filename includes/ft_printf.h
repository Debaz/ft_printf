#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

# define FLAGS "hljz"

int					ft_printf(char *fmt, ...);
int					ft_strlen(char const *s);
char				*ft_strndup(char *s, int n);

/*
** Conversion functions
*/

char				*add_ptr(void *ptr);
char				*add_octal(int n, int mod);
char				*add_uint(unsigned int n, int mod);
char				*add_hexa(int n);
char				*add_majhexa(int n);

#endif
