/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:13:00 by mploux            #+#    #+#             */
/*   Updated: 2016/11/07 17:16:49 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <libc.h>

char		*ft_strnew(size_t size)
{
	char *data;

	if (!(data = (char *)malloc(size + 1)))
		return (NULL);
	ft_bzero(data, size + 1);
	return (data);
}
