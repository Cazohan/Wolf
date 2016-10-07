/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 16:23:45 by lherbelo          #+#    #+#             */
/*   Updated: 2016/10/07 09:52:24 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		ft_place(t_mlx *m, int xmax, int ymax)
{
	int x;
	int y;

	DEBUG
	x = 0;
	while (x <= xmax)
	{
		y = 0;
		while (y <= ymax)
		{
			if (m->w->map[x][y] == 0 && m->w->map[x + 1][y] == 0 &&
				m->w->map[x - 1][y] == 0 && m->w->map[x][y + 1] == 0 &&
				m->w->map[x][y - 1] == 0)
			{
				m->w->posx = x;
				m->w->posy = y;
			}
			else
				y++;
		}
	x++;
	}
	DEBUG
}

void		ft_full(t_mlx *m, char *av)
{
	char	*line;
	char	**tmp;
	int		fd;

	fd = open(av, O_RDONLY);
	m->w->x = 0;
	while (get_next_line(fd, &line))
	{
		m->w->y = 0;
		tmp = ft_strsplit(line, ' ');
		while (tmp[m->w->y] != NULL)
		{
			m->w->map[m->w->x][m->w->y] = ft_atoi(tmp[m->w->y]);
			m->w->y++;
		}
		m->w->x++;
	}
	ft_place(m, m->w->x, m->w->y);
}

int			**ft_size(t_mlx *m, int x, int y)
{
	int i;

	i = 0;
	m->w->map = (int **)ft_memalloc(sizeof(int *) * x);
	while (i < m->w->y)
	{
		m->w->map[i] = (int *)ft_memalloc(sizeof(int *) * y);
		i++;
	}
	return (m->w->map);
}

void		ft_parse(t_mlx *m, char *av)
{
	char	*line;
	char	**tmp;
	int		fd;

	fd = open(av, O_RDONLY);
	m->w->y = 0;
	while (get_next_line(fd, &line))
	{
		m->w->x = 0;
		tmp = ft_strsplit(line, ' ');
		while (tmp[m->w->x] != NULL)
			m->w->x++;
		m->w->y++;
	}
	ft_size(m, m->w->x + 1, m->w->y + 1);
	ft_full(m, av);
}
