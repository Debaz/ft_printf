/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 14:46:04 by klescaud          #+#    #+#             */
/*   Updated: 2016/08/08 16:33:26 by klescaud         ###   ########.fr       */
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

/*
** -----------------------------------------------------------------------------
** Main structure
*/

typedef struct	s_printf
{
	char			tab[2048];
	char			convlist[14]; // c, s, d, i, e, f, g, p, u, o, x, X, %.
	intmax_t		int_max;
	uintmax_t		uint_max;
	wchar_t			bufchar;
	wchar_t			*bufstr;
	void			*bufvoid;
	size_t			index;
	size_t			print_count;
	va_list			args;
}				t_printf;

/*
** -----------------------------------------------------------------------------
** Main printf
*/

int		ft_printf(const char *format, ...);
void	init_printf(t_printf *data);
void	discharge_tab(t_printf *data, size_t size);
void	stock_printf(t_printf *data, const char *format);
void	printf_conv(const char *format, t_printf *data, int *i);
int		check_conv(char c, char *covlist);
void	init_convlist(char *convlist);

#endif
