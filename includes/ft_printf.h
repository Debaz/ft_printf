/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:48:16 by klescaud          #+#    #+#             */
/*   Updated: 2016/02/16 15:44:21 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <libft.h>

/*
** CONV macro : Contains every possible flags in format string
*/

# define CONV "sSpdDioOuUxXcC"

/*
** Main format structure :
** format => Array containing all strings and flags passed in argument
** types => Array containing all types of variables passed in argument
** nbargs => Number of arguments;
*/

typedef struct			s_ptfinfo{
	char			**format;
	char			**types;
	unsigned int	nbargs;
}						t_ptfinfo;

/*
** -----------------------------------------------------------------------------
*/

int		ft_printf(char *format, ...);

#endif
