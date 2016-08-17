/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columlor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 19:00:26 by lherbelo          #+#    #+#             */
/*   Updated: 2016/08/17 11:48:43 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		pixel_put(t_mlx *m, int x, int y, t_rgb *c)
{
	int		index;

	index = y * m->s_l + x * (m->bpp / 8);
	if (x < 800 && x > 0 && y < 800 && y > 0)
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

void		ft_column(t_mlx *m, int x)
{
	t_rgb	c;
	int		y;

	y = 0;
	select_color(&c, 0, 0, 0);
	while (y < m->w->drawS)
	{
		pixel_put(m, x, y, &c);
		y++;
	}
	y = m->w->drawS;
	select_color(&c, 250, 0, 0);
	while (y < m->w->drawE)
	{
		pixel_put(m, x, y, &c);
		y++;
	}
	y = m->w->drawE;
	select_color(&c, 175, 175, 175);
	while (y < m->height)
	{
		pixel_put(m, x, y, &c);
		y++;
	}
}
