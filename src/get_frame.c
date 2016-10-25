/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 19:18:48 by lherbelo          #+#    #+#             */
/*   Updated: 2016/10/25 11:26:11 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void					get_frame(t_mlx *m)
{
	struct timeval		time;

	m->w->otime = m->w->time;
	gettimeofday(&time, NULL);
	m->w->time = time.tv_sec * 1000 + time.tv_usec / 1000;
	m->w->frame = m->w->time - m->w->otime;
	m->w->rot_speed = m->w->frame * 0.003;
	if (m->w->run == 1)
		m->w->move_speed = m->w->frame * 0.020;
	if (m->w->run == 0)
		m->w->move_speed = m->w->frame * 0.005;
}

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
