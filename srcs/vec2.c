/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:31:28 by mploux            #+#    #+#             */
/*   Updated: 2016/11/14 17:12:50 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_vec2		int_to_vec2(int nb, int size)
{
	t_vec2	ret;

	ret.l = nb / size;
	ret.c = nb % size;
	return (ret);
}

t_vec2		vec2_add(t_vec2 v1, t_vec2 v2)
{
	t_vec2	ret;

	ret.l = v1.l + v2.l;
	ret.c = v1.c + v2.c;
	return (ret);
}

t_vec2		vec2_sub(t_vec2 v1, t_vec2 v2)
{
	t_vec2	ret;

	ret.l = v1.l - v2.l;
	ret.c = v1.c - v2.c;
	return (ret);
}

int			vec2_equ(t_vec2 v1, t_vec2 v2)
{
	return (v1.l == v2.l && v1.c == v2.c);
}

t_vec2		vec2(int l, int c)
{
	t_vec2 v;

	v.l = l;
	v.c = c;
	return (v);
}
