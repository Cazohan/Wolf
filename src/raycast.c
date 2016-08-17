/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 18:32:49 by lherbelo          #+#    #+#             */
/*   Updated: 2016/08/09 16:13:43 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		ft_ray_pos(t_mlx *m, int x)
{
	m->w->camX = 2 * x / (double)m->width - 1;
	m->w->rayposX = m->w->posX;
	m->w->rayposY = m->w->posY;
	m->w->raydirX = m->w->dirX + m->w->planeX * m->w->camX;
	m->w->raydirY = m->w->dirY + m->w->planeY * m->w->camX;
	m->w->mapX = (int)m->w->rayposX;
	m->w->mapY = (int)m->w->rayposY;
	m->w->d_distX = sqrt( 1 + (m->w->raydirY * m->w->raydirY) / (m->w->raydirX * m->w->raydirX));
	m->w->d_distY = sqrt( 1 + (m->w->raydirX * m->w->raydirX) / (m->w->raydirY * m->w->raydirY));
}

void		ft_step(t_mlx *m)
{
	if (m->w->raydirX < 0)
	{
		m->w->stepX = -1;
		m->w->s_distX = (m->w->rayposX - m->w->mapX) * m->w->d_distX;
	}
	else
	{
		m->w->stepX = 1;
		m->w->s_distX = (m->w->mapX + 1.0 - m->w->rayposX) * m->w->d_distX;
	}
	if (m->w->raydirY < 0)
	{
		m->w->stepY = -1;
		m->w->s_distY = (m->w->rayposY - m->w->mapY) * m->w->d_distY;
	}
	else
	{
		m->w->stepY = 1;
		m->w->s_distY = (m->w->mapY + 1.0 - m->w->rayposY) * m->w->d_distY;
	}
}

void		ft_dda(t_mlx *m)
{
	m->w->hit = 0;
	while (m->w->hit == 0)
	{
		if (m->w->s_distX < m->w->s_distY)
		{
			m->w->s_distX += m->w->d_distX;
			m->w->mapX += m->w->stepX;
			m->w->side = 0;
		}
		else
		{
			m->w->s_distY += m->w->d_distY;
			m->w->mapY += m->w->stepY;
			m->w->side = 1;
		}
		if (m->w->map[m->w->mapX][m->w->mapY] > 0)
			m->w->hit = 1;
	}
}

void		ft_dist(t_mlx *m)
{
	if (m->w->side == 0)
		m->w->ppwallD = (m->w->mapX - m->w->rayposX + ( 1 - m->w->stepX) / 2) / m->w->raydirX;
	else
		m->w->ppwallD = (m->w->mapY - m->w->rayposY + ( 1 - m->w->stepY) / 2) / m->w->raydirY;
	m->w->lineH = 800 / m->w->ppwallD;
	m->w->drawS = -(m->w->lineH) / 2 + 800 / 2;
	if (m->w->drawS < 0)
		m->w->drawS = 0;
	m->w->drawE = m->w->lineH / 2 + 800 / 2;
	if (m->w->drawE >= 800)
		m->w->drawE = 800 - 1;
}

