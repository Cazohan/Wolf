/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columlor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 19:00:26 by lherbelo          #+#    #+#             */
/*   Updated: 2016/10/15 13:04:08 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		pixel_put(t_mlx *m, int x, int y, t_rgb *c)
{
	int		index;

	index = y * m->s_l + x * (m->bpp / 8);
	if (x < m->width && x > 0 && y < m->height && y > 0)
	{
		m->data[index] = c->b;
		m->data[index + 1] = c->g;
		m->data[index + 2] = c->r;
	}
}

void		select_color(t_rgb *c, int r, int g, int b)
{
	c->r = r;
	c->g = g;
	c->b = b;
}

void		ft_column(t_mlx *m, t_rgb *c, int x)
{
	int		y;
	t_rgb	skyfloor;

	y = 0;
	select_color(&skyfloor, 0, 0, 0);
	while (y < m->w->draws)
	{
		pixel_put(m, x, y, &skyfloor);
		y++;
	}
	y = m->w->draws;
	while (y < m->w->drawe)
	{
		pixel_put(m, x, y, c);
		y++;
	}
	y = m->w->drawe;
	select_color(&skyfloor, 175, 175, 175);
	while (y < m->height)
	{
		pixel_put(m, x, y, &skyfloor);
		y++;
	}
}
