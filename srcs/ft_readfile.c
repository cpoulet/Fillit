/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:31:13 by mploux            #+#    #+#             */
/*   Updated: 2016/11/15 08:55:02 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checkline(char *line)
{
	int i;

	i = -1;
	while (line[++i] && i < 4)
		if (line[i] != '.' && line[i] != '#')
			return (0);
	if (line[i] != '\n')
		return (0);
	return (1);
}

void	ft_cpy_tetri(char src[4][4], char dest[4][4])
{
	int i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			dest[i][j] = src[i][j];
	}
}

int		ft_add_tetri(t_tetri **set, char piece[4][4])
{
	t_tetri	*tetri;
	t_tetri *tmp;
	int		i;

	i = 1;
	if (!(tetri = (t_tetri*)malloc(sizeof(*tetri))))
		return (0);
	tmp = *set;
	if (tmp)
	{
		while (++i && tmp->next)
			tmp = tmp->next;
		tmp->next = tetri;
	}
	else
		*set = tetri;
	tetri->id = i;
	ft_cpy_tetri(piece, tetri->piece);
	get_origin(tetri);
	if (!ft_is_valid_tetri(tetri))
		return (0);
	tetri->next = NULL;
	return (1);
}

int		ft_readfile(t_file *file)
{
	int		ret;
	char	line[5];
	char	tmp[4][4];
	int		i;

	i = 0;
	ret = 1;
	while (i++ < 4 && ret > 0)
	{
		ret = read(file->fd, line, 5);
		if (ret && (ret = ft_checkline(line)))
			ft_memcpy(tmp[i - 1], line, 4);
	}
	if (ret <= 0 || i < 4)
		return (0);
	if (!ft_add_tetri(&file->set, tmp))
		return (0);
	ret = read(file->fd, line, 1);
	if (ret && *line != '\n')
		return (0);
	if (ret && *line == '\n')
		if (!ft_readfile(file))
			return (0);
	return (1);
}
