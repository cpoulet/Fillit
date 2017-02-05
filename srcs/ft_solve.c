/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:31:17 by mploux            #+#    #+#             */
/*   Updated: 2016/11/14 21:45:25 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_tab_ralloc(t_file **file)
{
	int		i;
	int		j;

	i = -1;
	if ((*file)->grid)
	{
		while (++i < (*file)->size)
			ft_strdel(&(*file)->grid[i]);
		free((*file)->grid);
	}
	i = -1;
	(*file)->size++;
	(*file)->grid = (char**)malloc(sizeof(char*) * (*file)->size);
	while (++i < (*file)->size)
	{
		(*file)->grid[i] = ft_strnew((*file)->size);
		j = -1;
		while (++j < (*file)->size)
			(*file)->grid[i][j] = '.';
	}
}

void	ft_erase_tetri(t_file **file, t_vec2 vec, t_tetri *tetri, int print)
{
	int		i;
	t_vec2	vec1;

	i = -1;
	while (++i < 4)
	{
		vec1 = vec2_sub(tetri->form[i], tetri->origin);
		vec1 = vec2_add(vec, vec1);
		if (print)
			(*file)->grid[vec1.l][vec1.c] = tetri->id + 64;
		else
			(*file)->grid[vec1.l][vec1.c] = '.';
	}
}

int		ft_place_tetri(t_file **file, int pos, t_tetri *tetri)
{
	t_vec2	vec;
	int		i;

	i = -1;
	if (!tetri)
		return (1);
	if (pos == (*file)->size * (*file)->size - 2)
		return (0);
	while (++i < 4)
	{
		vec = vec2_sub(tetri->form[i], tetri->origin);
		vec = vec2_add(vec, int_to_vec2(pos, (*file)->size));
		if (vec.l >= (*file)->size || vec.c >= (*file)->size
				|| (*file)->grid[vec.l][vec.c] != '.')
			return (ft_place_tetri(file, pos + 1, tetri));
	}
	ft_erase_tetri(file, int_to_vec2(pos, (*file)->size), tetri, 1);
	if (!(ft_place_tetri(file, 0, tetri->next)))
	{
		ft_erase_tetri(file, int_to_vec2(pos, (*file)->size), tetri, 0);
		return (ft_place_tetri(file, pos + 1, tetri));
	}
	return (1);
}

int		ft_size_ok(t_file **file)
{
	int		pos;

	pos = 0;
	if (!(ft_place_tetri(file, pos, (*file)->set)))
		return (0);
	return (1);
}

int		ft_solve(t_file *file)
{
	int	i;
	int	j;

	i = -1;
	if (!(file->grid = (char**)malloc(sizeof(char*) * file->size)))
		return (0);
	while (++i < file->size)
	{
		file->grid[i] = ft_strnew(file->size);
		j = -1;
		while (++j < file->size)
			file->grid[i][j] = '.';
	}
	while (!(ft_size_ok(&file)))
		ft_tab_ralloc(&file);
	return (1);
}
