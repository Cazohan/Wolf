/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 19:18:48 by lherbelo          #+#    #+#             */
/*   Updated: 2016/08/09 16:15:21 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void					get_frame(t_mlx *m)
{
	struct timeval		time;// man gettimeofday pour comprendre la structure time de type timeval

	m->w->otime = m->w->time;
	gettimeofday(&time, NULL);
	m->w->time = time.tv_sec * 1000 + time.tv_usec / 1000;// tv_sec = seconde tv_usec = micro_seconde
	m->w->frame = m->w->time - m->w->otime;
	m->w->rot_speed = m->w->frame * 0.003;//sensibiliter rotation camera
	m->w->move_speed = m->w->frame * 0.005;//sensibiliter deplacement
}
