/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 20:25:25 by angkim            #+#    #+#             */
/*   Updated: 2019/08/13 14:15:32 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” memory area.
** The memory allocated is initialized to 0.
** If the allocation fails, the function returns NULL.
*/

void	*ft_memalloc(size_t size)
{
	void *new;

	new = (void *)malloc(size);
	if (new)
	{
		ft_bzero(new, size);
		return (new);
	}
	return (NULL);
}
