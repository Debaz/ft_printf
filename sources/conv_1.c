/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 14:37:56 by klescaud          #+#    #+#             */
/*   Updated: 2016/08/17 17:26:36 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	printf_conv(const char *format, t_printf *data, int *i)
{
	// TEMPORARY FUNCTION
	++*(i);
	while (!check_conv(format[*i], data->convlist))
		++*(i);
	++*(i);
	data->tab[data->index] = '4';
	++data->index;
	data->tab[data->index] = '2';
	++data->index;
}

int		check_conv(char c, char *convlist)
{
	int		i;

	i = 0;
	while (convlist[i])
	{
		if (c == convlist[i])
			return (1);
		++i;
	}
	return (0);
}
