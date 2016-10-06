/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 16:25:13 by lherbelo          #+#    #+#             */
/*   Updated: 2016/10/06 10:11:25 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void		ft_turn(t_mlx *m, int dir)
{
	double		tmpdir;
	double		tmpplane;
	int			coef;

	coef = 1;
	tmpdir = m->w->dirx;
	tmpplane = m->w->planex;
	if (dir == 1)
		coef = -1;
	m->w->dirx = m->w->dirx * cos(coef * m->w->rot_speed)
									- m->w->diry * sin(coef * m->w->rot_speed);
	m->w->diry = tmpdir * sin(coef * m->w->rot_speed)
									+ m->w->diry * cos(coef * m->w->rot_speed);
	m->w->planex = m->w->planex * cos(coef * m->w->rot_speed)
								- m->w->planey * sin(coef * m->w->rot_speed);
	m->w->planey = tmpplane * sin(coef * m->w->rot_speed)
								+ m->w->planey * cos(coef * m->w->rot_speed);
}

void		ft_move(t_mlx *m)
{
	if (m->w->up)
	{
		if (!(m->w->map[(int)(m->w->posx + m->w->dirx)][(int)m->w->posy]))
			m->w->posx += m->w->dirx * m->w->move_speed;
		if (!(m->w->map[(int)m->w->posx][(int)(m->w->posy + m->w->diry)]))
			m->w->posy += m->w->diry * m->w->move_speed;
	}
	if (m->w->left)
		ft_turn(m, 0);
	if (m->w->right)
		ft_turn(m, 1);
	if (m->w->down)
	{
		if (!(m->w->map[(int)(m->w->posx - m->w->dirx)][(int)m->w->posy]))
			m->w->posx -= m->w->dirx * m->w->move_speed;
		if (!(m->w->map[(int)m->w->posx][(int)(m->w->posy - m->w->diry)]))
			m->w->posy -= m->w->diry * m->w->move_speed;
	}
}

int			ft_k_press(int key, t_mlx *m)
{
	if (key == 13 || key == 126)
		m->w->up = 1;
	else if (key == 125 || key == 1)
		m->w->down = 1;
	else if (key == 123 || key == 0)
		m->w->left = 1;
	else if (key == 124 || key == 2)
		m->w->right = 1;
	return (0);
}

int			ft_k_release(int key, t_mlx *m)
{
	if (key == 53)
	{
		mlx_destroy_image(m->mlx, m->img);
		mlx_destroy_window(m->mlx, m->win);
		exit(0);
	}
	else if (key == 13 || key == 126)
		m->w->up = 0;
	else if (key == 125 || key == 1)
		m->w->down = 0;
	else if (key == 123 || key == 0)
		m->w->left = 0;
	else if (key == 124 || key == 2)
		m->w->right = 0;
	return (0);
}
