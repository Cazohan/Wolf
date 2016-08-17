/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 16:23:45 by lherbelo          #+#    #+#             */
/*   Updated: 2016/07/24 16:57:27 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		ft_full(t_mlx *m, char *av)
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
		{
			m->w->map[m->w->x][m->w->y] = ft_atoi(tmp[m->w->x]);
			m->w->x++;
		}
		m->w->y++;
	}
}

int			**ft_size(t_mlx *m)
{
	int i;

	i = 0;
	m->w->map = (int **)ft_memalloc(sizeof(int *) * m->w->y);
	while (i < m->w->y)
	{
		m->w->map[i] = (int *)ft_memalloc(sizeof(int *) * m->w->x);
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
	ft_size(m);
	ft_full(m, av);
}
