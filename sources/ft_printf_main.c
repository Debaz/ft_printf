/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 15:29:53 by klescaud          #+#    #+#             */
/*   Updated: 2016/08/08 16:35:15 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_printf(const char *format, ...)
{
	t_printf	data;

	init_printf(&data);
	va_start(data.args, format);
//-----
	stock_printf(&data, format);
//-----
	va_end(data.args);
	return ((int)data.print_count);
}

void	init_printf(t_printf *data)
{
	init_convlist(data->convlist);
	data->int_max = 0;
	data->uint_max = 0;
	data->bufchar = 0;
	data->bufstr = NULL;
	data->bufvoid = NULL;
	data->index = (size_t)0;
	data->print_count = (size_t)0;
}

void	discharge_tab(t_printf *data, size_t size)
{
	if (data->index + size > 2048)
	{
		write(1, data->tab, data->index);
		data->print_count += data->index;
		data->index = 0;
	}
}

void	stock_printf(t_printf *data, const char *format)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			printf_conv(format, data, &i);
		}
		discharge_tab(data, 1);
		data->tab[data->index] = format[i];
		++data->index;
		i++;
	}
	write(1, data->tab, data->index);
	data->print_count += data->index;
}


void	printf_conv(const char *format, t_printf *data, int *i)
{
	while (!check_conv(format[*i], data->convlist))
	{
		// Inclure ici la creation du masque param par param
		++(*i);
	}
	//calcul de la conv (application du masque), discharge de la taille obtenue et ecriture
	// ----- (Inscription temporaire de CONV lors d'une conversion)
	discharge_tab(data, 4);
	data->tab[data->index] = 'C';
	++data->index;
	data->tab[data->index] = 'O';
	++data->index;
	data->tab[data->index] = 'N';
	++data->index;
	data->tab[data->index] = 'V';
	++data->index;
	// -----
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

void	init_convlist(char *convlist)
{
	convlist[0] = 'c';
	convlist[1] = 's';
	convlist[2] = 'd';
	convlist[3] = 'i';
	convlist[4] = 'e';
	convlist[5] = 'f';
	convlist[6] = 'g';
	convlist[7] = 'p';
	convlist[8] = 'u';
	convlist[9] = 'o';
	convlist[10] = 'x';
	convlist[11] = 'X';
	convlist[12] = '%';
	convlist[13] = '\0';
}
