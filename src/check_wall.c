/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:10:26 by lherbelo          #+#    #+#             */
/*   Updated: 2016/10/25 11:24:30 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		ft_color_wall(t_mlx *m, t_rgb *c)
{
	if (m->w->side == 0)
	{
		if (m->w->stepx == -1)
			select_color(c, 120, 150, 210);
		else
			select_color(c, 120, 210, 110);
	}
	else if (m->w->side == 1 && m->w->hit == 1)
	{
		if (m->w->stepy == -1)
			select_color(c, 20, 70, 31);
		else
			select_color(c, 90, 10, 10);
	}
}

void		ft_fixc(t_mlx *m, t_rgb *c)
{
	if (m->w->map[m->w->mapx][m->w->mapy] == 2)
		select_color(c, 210, 210, 0);
	else if (m->w->map[m->w->mapx][m->w->mapy] == 5)
		select_color(c, 250, 110, 80);
	else
		ft_color_wall(m, c);
}
