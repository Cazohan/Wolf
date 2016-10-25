/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:47:17 by lherbelo          #+#    #+#             */
/*   Updated: 2016/10/25 11:22:32 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		ft_inside_2(t_mlx *m, int x, int y)
{
	x = 0;
	while (x < m->w->width_m)
	{
		y = 0;
		while (y < m->w->height_m)
		{
			if ((x == 7 && y == 8) || (x == 7 && y == 9) || (x == 7 && y == 10)
				|| (x == 8 && y == 8) || (x == 8 && y == 9) || (x == 8 &&
				y == 10))
				m->w->map[x][y] = 2;
			else if ((x == 8 && y == 7) || (x == 9 && y == 4) || (x == 9 &&
					y == 5) || (x == 9 && y == 7) || (x == 10 && y == 9))
				m->w->map[x][y] = 5;
			y++;
		}
		x++;
	}
}

void		ft_inside_1(t_mlx *m, int x, int y)
{
	x = 0;
	while (x < m->w->width_m)
	{
		y = 0;
		while (y < m->w->height_m)
		{
			if ((x == 2 && y == 5) || (x == 2 && y == 9) || (x == 3 && y == 4)
					|| (x == 3 && y == 7) || (x == 3 && y == 8) ||
						(x == 4 && y == 1))
				m->w->map[x][y] = 1;
			else if ((x == 4 && y == 2) || (x == 4 && y == 3) || (x == 4 &&
				y == 8) || (x == 5 && y == 5) || (x == 5 && y == 6))
				m->w->map[x][y] = 1;
			else if ((x == 6 && y == 2) || (x == 6 && y == 3) || (x == 6 &&
				y == 6) || (x == 7 && y == 2) || (x == 7 && y == 4))
				m->w->map[x][y] = 1;
			else if ((x == 5 && y == 9) || (x == 7 && y == 6) || (x == 8 &&
				y == 2) || (x == 9 && y == 2) || (x == 9 && y == 3))
				m->w->map[x][y] = 1;
			y++;
		}
		x++;
	}
}

void		ft_around(t_mlx *m)
{
	int		x;
	int		y;

	x = 0;
	while (x < m->w->width_m)
	{
		y = 0;
		while (y < m->w->height_m)
		{
			if (x == 0 || y == 0 || x == (m->w->width_m - 1) ||
					y == (m->w->height_m - 1))
				m->w->map[x][y] = 1;
			y++;
		}
		x++;
	}
}

void		ft_full(t_mlx *m)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_around(m);
	ft_inside_1(m, x, y);
	ft_inside_2(m, x, y);
}
