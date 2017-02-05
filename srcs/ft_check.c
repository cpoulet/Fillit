/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:31:07 by mploux            #+#    #+#             */
/*   Updated: 2016/11/14 21:42:23 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			tetri_size(char grid[4][4])
{
	int i;
	int len;

	i = -1;
	len = 0;
	while (++i < 4 * 4)
		if (grid[i / 4][i % 4] == '#')
			len++;
	return (len);
}

int			containes(t_vec2 v, t_vec2 tetri[4])
{
	int i;

	i = -1;
	while (++i < 4)
		if (vec2_equ(v, tetri[i]))
			return (1);
	return (0);
}

int			is_connected(t_vec2 tetri[4])
{
	int i;
	int hit;

	i = -1;
	hit = 0;
	while (++i < 4)
	{
		if (containes(vec2(tetri[i].l, tetri[i].c + 1), tetri))
			hit++;
		if (containes(vec2(tetri[i].l, tetri[i].c - 1), tetri))
			hit++;
		if (containes(vec2(tetri[i].l + 1, tetri[i].c), tetri))
			hit++;
		if (containes(vec2(tetri[i].l - 1, tetri[i].c), tetri))
			hit++;
	}
	return (hit > 4 ? 1 : 0);
}

int			ft_is_valid_tetri(t_tetri *tetri)
{
	int errors;

	errors = 0;
	errors += !(tetri_size(tetri->piece) == 4);
	errors += !(is_connected(tetri->form));
	if (errors == 0)
		return (1);
	return (0);
}
