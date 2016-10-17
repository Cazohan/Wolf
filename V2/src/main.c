/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 15:18:57 by lherbelo          #+#    #+#             */
/*   Updated: 2016/10/17 15:42:20 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		ft_error(t_mlx *m, int i)
{
	if (i == 1)
		ft_putstr("Seriously... this map ? Don't kidding me please :)\n");
	if (i == 2)
		ft_putstr("hummm... I see a hole in the map. TILT !\n");
	if (i == 3)
		ft_putstr("You know nothing J.. ok, ok calm down, I gonna stop this\n");
	if (m->img != NULL)
		mlx_destroy_image(m->mlx, m->img);
	mlx_destroy_window(m->mlx, m->win);
	exit(0);
}

int			ft_echap(t_mlx *m)
{
	ft_putstr("See ya !\n");
	mlx_destroy_image(m->mlx, m->img);
	mlx_destroy_window(m->mlx, m->win);
	exit(0);
	return (0);
}

int			main(void)
{
	t_mlx	m;

	ft_init(&m);
	mlx_hook(m.win, 17, 1, ft_echap, &m);
	mlx_hook(m.win, 3, (1L << 1), ft_k_release, &m);
	mlx_hook(m.win, 2, (1L << 0), ft_k_press, &m);
	mlx_loop_hook(m.mlx, ft_loop_ray, &m);
	mlx_loop(m.mlx);
	return (0);
}
