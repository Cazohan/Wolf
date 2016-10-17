/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 19:18:48 by lherbelo          #+#    #+#             */
/*   Updated: 2016/10/17 15:44:42 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void					get_frame(t_mlx *m)
{
	struct timeval		time;

	m->w->otime = m->w->time;
	gettimeofday(&time, NULL);
	m->w->time = time.tv_sec * 1000 + time.tv_usec / 1000;
	m->w->frame = m->w->time - m->w->otime;
	m->w->rot_speed = m->w->frame * 0.003;
	if (m->w->run == 1)
		m->w->move_speed = m->w->frame * 0.020;
	if (m->w->run == 0)
		m->w->move_speed = m->w->frame * 0.005;
}
