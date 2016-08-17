/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 15:29:53 by klescaud          #+#    #+#             */
/*   Updated: 2016/08/17 17:26:09 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_printf(const char *format, ...)
{
	t_printf	data;

	init_printf(&data);
	va_start(data.args, format);
//-----
	main_printf(&data, format);
//-----
	va_end(data.args);
	display_printf(&data);
	return ((int)data.print_count);
}

void	init_printf(t_printf *data)
{
	ft_bzero(data->convlist, 14);
	ft_strcpy(data->convlist, "csdiefgpuoxX%");
	data->int_max = 0;
	data->uint_max = 0;
	data->wchar = 0;
	data->bufstr = NULL;
	data->bufvoid = NULL;
	data->bufwchar = 0;
	data->index = (size_t)0;
	data->print_count = (size_t)0;
}

void	main_printf(t_printf *data, const char *format)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			printf_conv(format, data, &i);
		else
			stock_printf(format, data, &i);
	}
}
