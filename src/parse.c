/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 16:23:45 by lherbelo          #+#    #+#             */
/*   Updated: 2016/10/10 12:15:44 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		ft_place(t_mlx *m)
{
	int		x;
	int		y;
	int		search;

	search = 1;
	x = 0;
	while (x < m->w->x && search)
	{
		y = 0;
		while (y < m->w->y && search)
		{
			if (m->w->map[x][y] == 0 && m->w->map[x + 1][y]  == 0 &&
					m->w->map[x - 1][y] == 0 && m->w->map[x][y + 1] == 0 &&
					m->w->map[x][y - 1] == 0)
			{
				m->w->posx = x + 0.5;
				m->w->posy = y + 0.5;
				search = 0;
			}
			y++;
		}
		x++;
	}
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
		printf("%s\n", line);
		tmp = ft_strsplit(line, ' ');
		while (tmp[m->w->y] != NULL)
		{
			m->w->map[m->w->x][m->w->y] = ft_atoi(tmp[m->w->y]);
			m->w->y++;
		}
		m->w->x++;
	}
	close(fd);
}

int			**ft_size(t_mlx *m, int x, int y)
{
	int i;

	i = 0;
	m->w->map = (int **)ft_memalloc(sizeof(int *) * x);
	while (i < x)
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
	m->w->x = 0;
	while (get_next_line(fd, &line))
	{
		m->w->y = 0;
		tmp = ft_strsplit(line, ' ');
		while (tmp[m->w->y] != NULL)
			m->w->y++;
		m->w->x++;
	}
	close(fd);
	DEBUG
	ft_size(m, m->w->x + 1, m->w->y + 1);
	DEBUG
	ft_full(m, av);
	DEBUG
	ft_place(m);
	DEBUG
}
