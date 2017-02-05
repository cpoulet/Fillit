/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:31:02 by mploux            #+#    #+#             */
/*   Updated: 2016/11/15 10:58:34 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_display_grid(t_file *file)
{
	int	i;

	if (!(file->grid))
		return ;
	i = -1;
	while (++i < file->size)
	{
		write(1, file->grid[i], file->size);
		write(1, "\n", 1);
	}
}

int		ft_sizesquare(t_file *file)
{
	t_tetri	*tmp;
	int		i;

	i = 2;
	tmp = file->set;
	while (tmp && ++file->nb)
		tmp = tmp->next;
	if (file->nb == 0 || file->nb > 26)
		return (0);
	while (i * i < file->nb * 4)
		i++;
	file->size = i;
	return (1);
}

int		main(int ac, char **av)
{
	t_file	file;

	if (ac != 2)
	{
		write(1, "usage: fillit source_file\n", 26);
		return (0);
	}
	file.fd = open(av[1], O_RDONLY);
	file.set = NULL;
	file.grid = NULL;
	file.nb = 0;
	if (!ft_readfile(&file) || (!ft_sizesquare(&file)))
	{
		write(1, "error\n", 6);
		return (0);
	}
	close(file.fd);
	if (!(ft_solve(&file)))
	{
		write(1, "error\n", 6);
		return (0);
	}
	ft_display_grid(&file);
	return (0);
}
