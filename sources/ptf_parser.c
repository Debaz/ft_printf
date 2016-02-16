/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:57:16 by ksoulard          #+#    #+#             */
/*   Updated: 2016/02/16 16:54:31 by ksoulard         ###   ########.fr       */
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
	info->format_array = NULL;
	info->nbargs = 0;
	info->types = NULL;
	return (0);
}

/*
**	check_charconv => check the char for the conversion and
** 				  	  increment the info->nbargs if is exist.
*/

int				check_charconv(char c, char *conv, unsigned int nbargs)
{
	int			i;

	i = 0;
	while (conv[i])
	{
		if (conv[i] == c)
			break ;
		i++;
	}
	if (conv[i] != 0)
		nbargs++;
	return (conv[i]);
}

/*
**	check_nbconversion => get the numbers of conversion on the format string
*/

void			check_nbconversion(char *format, t_pftinfo **info)
{
	int			i;
	int			booll;
	char		*conv;
	int			nbformat;

	i = 0;
	nbformat = 1;
	if ((conv = ft_strdup(CONV)) == NULL)
		return (-1);
	while (format[i])
	{
		booll = 0;
		if (format[i] == '%')
		{
			booll = 1;
			if (check_charconv(format[i], conv, (*info)->nbargs) != 0)
				nbformat++;
			i++;
		}
		if (booll = 1)
			nbformat++;
		i++;
	}
	return (nbformat);
}

/*
**	check_types => return an array wich contains every
**				   types of varuables passed in arguments
*/

/*
**	check_format => return an array wich contains every
**					format of variable passed in arguments
*/
char			**check_format(char *format, int nbargs)
{
	char		**types;
	int			i;
	char		*s;

	i = 0;
	if ((types = (char **)malloc(sizeof(char *) * nbargs + 1)) == NULL)
		return (NULL);
	types[nbargs] = NULL;
	while (42)
	{
		if ((s = ft_strchr(format, '%')) != NULL)
		{
			if ((types[i] = ft_strndup(format, s - format)) == NULL)
				return (ft_free_tab((void **)types));
			format = s;
			i++;
		}
		else
		{
			if ((types[i] = ft_strdup(format)) == NULL)
				return (ft_free_tab((void **)types));
			break ;
		}
	}
	return (types);
}

/*
**	str_parser => parse and check the errors of the ft_printf string
*/

// info->format_array = (char **)malloc(sizeof(char *) * nbformat + 1);
// info->format_array[nbformat] = NULL;

ptf_info		str_parser(char *format)
{
	t_ptfinfo	*info;
	int			nbconv;

	if (format == NULL)
		return (NULL);
	if (ft_strcmp(format, "") == 0)
		return (NULL);
	if (init_info(info) == -1)
		return (NULL);
	nbconv = check_nbconversion(format, &info);
	info->types = check_types(format, info->nbargs);
	info->format_array = check_format(format, nbconv);
	if (info->types == NULL || info->format_array == NULL)
		return (NULL);
}
