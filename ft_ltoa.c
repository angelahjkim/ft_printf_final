/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:40:20 by angkim            #+#    #+#             */
/*   Updated: 2019/10/02 10:32:30 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ltoa(long nbr)
{
	char	*num_str;
	int		size;

	num_str = NULL;
	size = ft_digitcount(nbr);
	if ((num_str = (char *)ft_memalloc(sizeof(char) * (size + 1))) == NULL)
		return (num_str);
	num_str[size] = '\0';
	if (nbr == 0)
	{
		num_str[0] = '0';
		return (num_str);
	}
	while (nbr)
	{
		num_str[size - 1] = (nbr % 10) + '0';
		nbr /= 10;
		size--;
	}
	return (num_str);
}
