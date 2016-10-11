/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:10:26 by lherbelo          #+#    #+#             */
/*   Updated: 2016/10/11 15:37:59 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		ft_check_wall(t_mlx *m)
{
	int		x;
	int		y;

	x = 0;
	while (x < m->w->x)
	{
		y = 0;
		while (y < m->w->y)
		{
			if (x == 0 || (x == m->w->x - 1))
				if (m->w->map[x][y] == 0)
					ft_error(m, 3);
			if (y == 0 || (y == m->w->y - 1))
				if (m->w->map[x][y] == 0)
					ft_error(m, 3);
			y++;
		}
		x++;
	}
}
