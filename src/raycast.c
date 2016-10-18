/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 18:32:49 by lherbelo          #+#    #+#             */
/*   Updated: 2016/10/17 15:45:56 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		ft_ray_pos(t_mlx *m, int x)
{
	m->w->camx = 2 * x / (double)m->width - 1;
	m->w->rayposx = m->w->posx;
	m->w->rayposy = m->w->posy;
	m->w->raydirx = m->w->dirx + m->w->planex * m->w->camx;
	m->w->raydiry = m->w->diry + m->w->planey * m->w->camx;
	m->w->mapx = (int)m->w->rayposx;
	m->w->mapy = (int)m->w->rayposy;
	m->w->d_distx = sqrt(1 + (m->w->raydiry * m->w->raydiry) /
			(m->w->raydirx * m->w->raydirx));
	m->w->d_disty = sqrt(1 + (m->w->raydirx * m->w->raydirx) /
			(m->w->raydiry * m->w->raydiry));
}

void		ft_step(t_mlx *m)
{
	if (m->w->raydirx < 0)
	{
		m->w->stepx = -1;
		m->w->s_distx = (m->w->rayposx - m->w->mapx) * m->w->d_distx;
	}
	else
	{
		m->w->stepx = 1;
		m->w->s_distx = (m->w->mapx + 1.0 - m->w->rayposx) * m->w->d_distx;
	}
	if (m->w->raydiry < 0)
	{
		m->w->stepy = -1;
		m->w->s_disty = (m->w->rayposy - m->w->mapy) * m->w->d_disty;
	}
	else
	{
		m->w->stepy = 1;
		m->w->s_disty = (m->w->mapy + 1.0 - m->w->rayposy) * m->w->d_disty;
	}
}

void		ft_dda(t_mlx *m)
{
	m->w->hit = 0;
	while (m->w->hit == 0)
	{
		if (m->w->s_distx < m->w->s_disty)
		{
			m->w->s_distx += m->w->d_distx;
			m->w->mapx += m->w->stepx;
			m->w->side = 0;
		}
		else
		{
			m->w->s_disty += m->w->d_disty;
			m->w->mapy += m->w->stepy;
			m->w->side = 1;
		}
		if (m->w->map[m->w->mapx][m->w->mapy] > 0)
			m->w->hit = 1;
	}
}

void		ft_dist(t_mlx *m)
{
	if (m->w->side == 0)
		m->w->ppwalld = (m->w->mapx - m->w->rayposx + (1 - m->w->stepx) / 2) /
			m->w->raydirx;
	else
		m->w->ppwalld = (m->w->mapy - m->w->rayposy + (1 - m->w->stepy) / 2) /
			m->w->raydiry;
	m->w->lineh = m->height / m->w->ppwalld;
	m->w->draws = -(m->w->lineh) / 2 + m->height / 2;
	if (m->w->draws < 0)
		m->w->draws = 0;
	m->w->drawe = m->w->lineh / 2 + m->height / 2;
	if (m->w->drawe >= m->height)
		m->w->drawe = m->height - 1;
}
