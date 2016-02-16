/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:47:45 by klescaud          #+#    #+#             */
/*   Updated: 2016/02/16 15:32:40 by klescaud         ###   ########.fr       */
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

int		ft_printf(char *format, ...)
{
	//WIP
}
