/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:47:45 by klescaud          #+#    #+#             */
/*   Updated: 2016/02/16 16:07:28 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Temporary test function
*/

int		main(void)
{
	int		ptfreturn;

	ptfreturn = ft_printf("My name is %s.\n", "Slim Shady");
	ft_putstr("ft_printf return value = ");
	ft_putnbr(ptfreturn);
	ft_putendl("");
	ft_putendl("-------------------------------------------------");
	ptfreturn = printf("My name is %s.\n", "Slim Shady");
	ft_putstr("printf return value = ");
	ft_putnbr(ptfreturn);
	ft_putendl("");
	return (0);
}


/*
** ft_printf => Reproduce the behaviour of printf function
*/

int		ft_printf(char *format, ...)
{
/*
** WIP
*/
	t_ptfinfo	*ptfinfo;
	size_t		res;

	res = 0;
	ptfinfo = str_parser(format);
	display_array(ptfinfo->format);
	res = array_size(ptfinfo->format);
	return (res);
}
