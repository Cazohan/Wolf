/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 13:56:09 by lherbelo          #+#    #+#             */
/*   Updated: 2016/10/06 10:09:24 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

int			ft_loop_ray(t_mlx *m)
{
	int		x;

	if (m->img != NULL)
		mlx_destroy_image(m->mlx, m->img);
	m->img = mlx_new_image(m->mlx, m->width, m->height);
	m->data = mlx_get_data_addr(m->img, &m->bpp, &m->s_l, &m->end);
	x = 0;
	while (x < m->width)
	{
		ft_ray_pos(m, x);
		ft_step(m);
		ft_dda(m);
		ft_dist(m);
		ft_column(m, x);
		x++;
	}
	get_frame(m);
	ft_move(m);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0,0);
	return (0);
}

void		ft_init(t_mlx *m, char *av)
{
	m->w = (t_wolf *)ft_memalloc(sizeof(t_wolf));
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, 800, 800, "Wolf");
	m->w->posx = 10;
	m->w->posy = 10;
	m->w->dirx = -1;
	m->w->diry = 0;
	m->w->planex = 0;
	m->w->planey = 0.60;
	m->w->time = 0;
	m->w->otime = 0;
	m->width = 800;
	m->height = 800;
	m->img = NULL;
	ft_parse(m, av);
}
