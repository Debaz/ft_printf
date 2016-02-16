/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 15:57:14 by klescaud          #+#    #+#             */
/*   Updated: 2016/02/16 16:06:31 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** display_array => Prints an array on stdout using ft_putendl.
*/

void		display_array(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		ft_putendl(array[i]);
		i++;
	}
}

/*
** array_size => Counts the number of char contained in an array.
*/

size_t		array_size(char **array)
{
	int		i;
	size_t	res;

	i = 0;
	res = 0;
	while (array[i])
	{
		res += ft_strlen(array[i]);
		i++;
	}
	return (res);
}
