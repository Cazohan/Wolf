/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:10:26 by lherbelo          #+#    #+#             */
/*   Updated: 2016/10/11 15:09:46 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		ft_check_wall(t_mlx *m)
{
	int		x;
	int		y;

	x = 0;
	while(x < m->w->x)
	{
		y = 0;
		while(y <- m->w->y)
		{
			if (m->w->map[0][y] > 0 || m->w->map[m->w->x][y] > 0||
					m->w->map[x][0] > 0 || m->w->map[x][m->w->y] > 0)
				y++;
 			else
				ft_error(m, 3);
		}
		x++;
	}
}
