/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:38:58 by mploux            #+#    #+#             */
/*   Updated: 2016/11/14 21:42:49 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef	struct		s_vec2
{
	int			l;
	int			c;
}					t_vec2;

typedef struct		s_tetri
{
	int				id;
	char			piece[4][4];
	t_vec2			origin;
	t_vec2			form[4];
	struct s_tetri	*next;
}					t_tetri;

typedef struct		s_file
{
	int			nb;
	int			fd;
	int			size;
	char		**grid;
	t_tetri		*set;
}					t_file;

int					ft_solve(t_file *file);
int					ft_readfile(t_file *file);
t_vec2				vec2(int l, int c);
t_vec2				vec2_sub(t_vec2 v1, t_vec2 v2);
t_vec2				vec2_add(t_vec2 v1, t_vec2 v2);
t_vec2				int_to_vec2(int nb, int size);
int					vec2_equ(t_vec2 v1, t_vec2 v2);
void				get_origin(t_tetri *tetri);
int					ft_is_valid_tetri(t_tetri *tetri);

#endif
