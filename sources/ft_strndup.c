/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:40:02 by ksoulard          #+#    #+#             */
/*   Updated: 2016/02/16 16:45:00 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char		*ft_strndup(char const *s, int n)
{
	char	*s2;

	if (!s)
		return (NULL);
	s2 = (char *)malloc(sizeof(*s) * n + 1);
	return (s2 ? ft_strncpy(s2, s, n) : 0);
}
