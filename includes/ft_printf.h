/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 14:46:04 by klescaud          #+#    #+#             */
/*   Updated: 2016/08/17 17:27:25 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Personnal implementation of the standard C function printf
*/

# include <libft.h>
# include <wchar.h>
# include <stdint.h>
# include <stdarg.h>

# define TAB_MAX 2048
# define ISNEG(X) (x < 0 ? 1 : -1)

/*
** -----------------------------------------------------------------------------
** Main structure
*/

typedef struct	s_printf
{
	char			tab[TAB_MAX];
	char			convlist[14]; // c, s, d, i, e, f, g, p, u, o, x, X, %.
	intmax_t		int_max;
	long long       uint_max;
	wchar_t			wchar;
	wchar_t			*bufwchar;
	void			*bufvoid;
	char			*bufstr;
	size_t			index;
	size_t			print_count;
	va_list			args;
}				t_printf;

/*
** -----------------------------------------------------------------------------
** ft_printf_main.c
*/

int		ft_printf(const char *format, ...);
void	init_printf(t_printf *data);
void	main_printf(t_printf *data, const char *format);

/*
** -----------------------------------------------------------------------------
** conv_1.c
*/

void	printf_conv(const char *format, t_printf *data, int *i);
int		check_conv(char c, char *convlist);

/*
** -----------------------------------------------------------------------------
** tools_1.c
*/

void	display_printf(t_printf *data);
void	stock_printf(const char *format, t_printf *data, int *i);
void	discharge_tab(t_printf *data, size_t size);

#endif
