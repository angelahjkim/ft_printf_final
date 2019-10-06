/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:40:20 by angkim            #+#    #+#             */
/*   Updated: 2019/10/06 15:43:03 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_llutoa(uint64_t nbr, int size, int len)
{
	char	*num_str;

	num_str = NULL;
	if ((num_str = (char *)ft_memalloc(sizeof(char) * (len + 1))) == NULL)
		return (num_str);
	num_str[len] = '\0';
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
