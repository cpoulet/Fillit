/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_origin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:31:11 by mploux            #+#    #+#             */
/*   Updated: 2016/11/14 15:31:11 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	get_origin(t_tetri *tetri)
{
	int		i;
	int		j;
	int		k;
	t_vec2	result;

	k = -1;
	i = -1;
	result.l = -1;
	result.c = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tetri->piece[i][j] == '#')
				tetri->form[++k] = vec2(i, j);
			if (tetri->piece[i][j] == '#' && result.l == -1)
				result.l = i;
			if (tetri->piece[j][i] == '#' && result.c == -1)
				result.c = i;
		}
	}
	tetri->origin = result;
}
