/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 13:53:00 by lherbelo          #+#    #+#             */
/*   Updated: 2016/08/09 13:53:40 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
//void		draw_pixel(t_mlx *m, int x, int y, t_rgb *rgb);
void		pixel_put(t_mlx *m, int x, int y, t_rgb *c)
{
	int		index;

	index = y * m->s_l + x * (m->bpp / 8);
	if (x < 800 && x > 0 && y < 800 && y > 0)
	{
		m->data[index] = c->b;
		m->data[index + 1] = c->g;
		m->data[index + 2] = c->r;
	}
}

void		select_color(t_rgb *c, int r, int g, int b)
{
	c->r = r;
	c->g = g;
	c->b = b;
}

void		ft_raycast(t_mlx *m)
{
	t_rgb	c;
	int		x;
	int		y;

	x = 0;
	while (x < 800)
	{
	// *1
		m->w->camX = 2 * x / (double)m->width - 1;
		m->w->rayposX = m->w->posX;
		m->w->rayposY = m->w->posY;
		m->w->raydirX = m->w->dirX + m->w->planeX * m->w->camX;
		m->w->raydirY = m->w->dirY + m->w->planeY * m->w->camX;
		m->w->mapX = (int)m->w->rayposX;
		m->w->mapY = (int)m->w->rayposY;
		m->w->d_distX = sqrt( 1 + (m->w->raydirY * m->w->raydirY) / (m->w->raydirX * m->w->raydirX));
		m->w->d_distY = sqrt( 1 + (m->w->raydirX * m->w->raydirX) / (m->w->raydirY * m->w->raydirY));

	// j'ai jeter un coup d'oeil et corriger un truc ici (tu fermais ta boucle x<800) or il faut pas la fermer ici
	// car il faut initialiser(*1) puis faire les calcul pour chaque x de l'ecran donc il faut faire les etapes(*2/3/4)
	// suivante pour chaque x jusqua 800

	/2
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

	/3
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
	
	/4
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
	/5 dessine la colone x
		
		int y;

		y = 0;
		while (y < haut du mur)
			dessine de la couleur du ciel en x et y
		y = haut du mur;
		while (y < bas du mur)
			dessine la couleur du mur (pour differencier les face il faut choisir puis dessiner)
		y = bas du mur;
		while (y < hauteur maxi fenetre)
			dessine le sol;

		y = 0;
		select_color(&c, 120, 10, 52);
		while (y < m->w->drawS)
		{
			pixel_put(m, x, y, &c);
			y++;
		}
		y = m->w->drawS;
		select_color(&c, 250, 0, 0);
		while (y < m->w->drawE)
		{
			pixel_put(m, x, y, &c);
			y++;
		}
		y = m->w->drawE;
		select_color(&c, 0, 0, 250);
		while (y < 800)
		{
			pixel_put(m, x, y, &c);
			y++;
		}
	// ducoup j'ai fermer la boucle et deplacer l'incrementation ici
		x++;
	}
	get_frame(m);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0,0);
}
*/
