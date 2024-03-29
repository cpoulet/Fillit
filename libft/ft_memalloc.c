/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:47:05 by mploux            #+#    #+#             */
/*   Updated: 2016/11/07 17:02:31 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <libc.h>

void		*ft_memalloc(size_t size)
{
	void *data;

	if (!(data = (void *)malloc(size)))
		return (NULL);
	ft_bzero(data, size);
	return (data);
}
