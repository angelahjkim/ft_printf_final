/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 22:55:15 by angkim            #+#    #+#             */
/*   Updated: 2019/08/13 14:23:17 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Computes the length of the string s up to the first maxlen bytes of s.
** Returns the number of characters that precede the terminating NUL character.
*/

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}
