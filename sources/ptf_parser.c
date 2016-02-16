/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:57:16 by ksoulard          #+#    #+#             */
/*   Updated: 2016/02/16 15:32:37 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
**	init_info => initialize t_ptfinfo structure
*/

int				init_info(t_ptfinfo *info)
{
	info = (t_ptfinfo *)malloc(sizeof(t_ptfinfo));
	if (info == NULL)
		return (-1);
	info->str = NULL;
	info->types = NULL;
	return (0);
}

/*
**	check_conversion => count the numbers of conversions
**					    check the conversion chars of the ft_printf string
*/
int				check_conversion(char *format, t_pftinfo *info)
{
	int			i;
	char		*conv;

	if ((conv = ft_strdup(CONV)) == NULL)
		return (-1);
	i = 0;
	while (format[i])
	{
		if ()
	}
}


/*
**	str_parser => parse and check the errors of the ft_printf string
*/

ptf_info		str_parser(char *format)
{
	t_ptfinfo	*info;

	if (format == NULL)
		return (NULL);
	if (ft_strcmp(format, "") == 0)
		return (NULL);
	if (init_info(info) == -1)
		return (NULL);
	if (check_conversion(format, info) == -1)
		return (NULL);
}
