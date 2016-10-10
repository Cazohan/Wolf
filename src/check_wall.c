/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:10:26 by lherbelo          #+#    #+#             */
/*   Updated: 2016/10/10 14:40:51 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		ft_wall_x(t_mlx *m)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while (x < m->w->x)
	{
		if (m->w->map[x][y] == 0)
			m->w->wall++;
		printf("%d map: x1 \n", m->w->map[x][y]);
		x++;
	}
	x = 0;
	y = m->w->y;
	while (x < m->w->x)
	{
		if (m->w->map[x][y] == 0)
			m->w->wall++;
		printf("%d map: x2 \n", m->w->map[x][y]);
		x++;
	}
}

void		ft_wall_y(t_mlx *m)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < m->w->y)
	{
		if (m->w->map[x][y] == 0)
			m->w->wall++;
		printf("%d map: y1 \n", m->w->map[x][y]);
		y++;
	}
	x = m->w->x;
	y = 0;
	while (y < m->w->y)
	{
		if (m->w->map[x][y] == 0)
			m->w->wall++;
		printf("%d map: y2 \n", m->w->map[x][y]);
		y++;
	}
}

int			ft_wall(t_mlx *m)
{
	ft_wall_x(m);
	ft_wall_y(m);
	if (m->w->wall == 0)
		return (1);
	else
		return (0);
}

