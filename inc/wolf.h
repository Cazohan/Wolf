/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 15:20:00 by lherbelo          #+#    #+#             */
/*   Updated: 2016/10/06 10:08:37 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <sys/time.h> // pour la fonction gettimeofday pour get_frame();
# define DEBUG printf("%d - %s - %s\n", __LINE__, __func__, __FILE__);

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_wolf
{
	int				x;
	int				y;
	int				**map;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineh;
	int				draws;
	int				drawe;
	int				up;
	int				down;
	int				right;
	int				left;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			otime;
	double			frame;
	double			camx;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	double			width;
	double			s_distx;
	double			s_disty;
	double			d_distx;
	double			d_disty;
	double			ppwalld;
	double			rot_speed;
	double			move_speed;
}					t_wolf;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				s_l;
	int				end;
	int				height;
	int				width;
	t_wolf			*w;
}					t_mlx;


void				ft_move(t_mlx *m);
void				ft_init(t_mlx *m, char *av);
void				ft_parse(t_mlx *m, char *av);
void				get_frame(t_mlx *m);
void				ft_ray_pos(t_mlx *m, int x);
void				ft_column(t_mlx *m, int x);
void				ft_step(t_mlx *m);
void				ft_dda(t_mlx *m);
void				ft_dist(t_mlx *m);
int					ft_loop_ray(t_mlx *m);
int					ft_k_release(int key, t_mlx *m);
int					ft_k_press(int key, t_mlx *m);

#endif
