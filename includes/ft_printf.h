/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:48:16 by klescaud          #+#    #+#             */
/*   Updated: 2016/02/17 10:51:20 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <libft.h>

/*
** -----------------------------------------------------------------------------
*/
# include <stdio.h>
/*
** -----------------------------------------------------------------------------
*/

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
	char			**format_array;
	char			**types;
	unsigned int	nbargs;
}						t_ptfinfo;

/*
** -----------------------------------------------------------------------------
** ptf_main.c
*/

int			ft_printf(char *format);

/*
** -----------------------------------------------------------------------------
** ptf_display.c
*/

void		display_array(char **array);
size_t		array_size(char **array);

/*
** -----------------------------------------------------------------------------
** ft_free_tab.c
*/

void		*ft_free_tab(void **tab);

/*
** -----------------------------------------------------------------------------
** ft_strndup.c
*/

char		*ft_strndup(char const *s, int n);

/*
** -----------------------------------------------------------------------------
** ptf_display.c
*/

int			init_info(t_ptfinfo *info);
int			check_charconv(char c, char *conv, unsigned int nbargs);
int			check_nbconversion(char *format, t_ptfinfo **info);
char		**check_format(char *format, int nbargs);
t_ptfinfo	*str_parser(char *format);

#endif
