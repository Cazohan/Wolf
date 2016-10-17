/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 15:20:00 by lherbelo          #+#    #+#             */
/*   Updated: 2016/10/17 15:53:20 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_wolf
{
	int				run;
	int				x;
	int				y;
	int				**map;
	int				height_m;
	int				width_m;
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
	int				wall;
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

void				ft_error(t_mlx *m, int i);
void				ft_stop(t_mlx *m, int i);
void				ft_move(t_mlx *m);
void				ft_init(t_mlx *m);
void				ft_parse(t_mlx *m, char *av);
void				get_frame(t_mlx *m);
void				ft_ray_pos(t_mlx *m, int x);
void				ft_column(t_mlx *m, t_rgb *c, int x);
void				ft_step(t_mlx *m);
void				ft_dda(t_mlx *m);
void				ft_dist(t_mlx *m);
void				ft_fixc(t_mlx *m, t_rgb *c);
void				ft_full(t_mlx *m);
int					ft_echap(t_mlx *m);
int					ft_loop_ray(t_mlx *m);
int					ft_k_release(int key, t_mlx *m);
int					ft_k_press(int key, t_mlx *m);
int					**ft_alloc(t_mlx *m);
void				ft_check_wall(t_mlx *m);
void				select_color(t_rgb *c, int r, int g, int b);
void				ft_color_wall(t_mlx *m, t_rgb *c);

#endif
