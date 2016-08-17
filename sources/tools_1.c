/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 16:07:32 by klescaud          #+#    #+#             */
/*   Updated: 2016/08/17 17:27:26 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	display_printf(t_printf *data)
{
	write(1, data->tab, data->index);
	data->print_count += data->index;
}

void	stock_printf(const char *format, t_printf *data, int *i)
{
	discharge_tab(data, 1);
	data->tab[data->index] = format[*i];
	++data->index;
	++*(i);
}

void	discharge_tab(t_printf *data, size_t size)
{
	if (data->index + size > TAB_MAX)
	{
		write(1, data->tab, data->index);
		data->print_count += data->index;
		data->index = 0;
	}
}
