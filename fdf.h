/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 10:51:00 by jostraye          #+#    #+#             */
/*   Updated: 2017/12/13 17:22:19 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# include "libft/libft.h"

typedef struct		s_line
{
	int			pente;
	int			ordonnee;
	int			diviseur;
	int			sign;

}					t_line;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				** mx;
	int				size_x;
	int				size_y;
}					t_env;

typedef struct		s_parameters
{
	t_point			ctr;
	t_point			fr;
	t_point			to;
	double			zm;
	double			theta;
	double			iota;
	double			khapa;
	double			dph;
}					t_parameters;

void	draw_grid(int i, int j, t_parameters pm, t_env e);
void	draw_line(t_point fr, t_point to, t_env e);
void	horizontal_draw(t_point fr, t_point to, t_env e);
void	slope_draw(t_point org, t_point dest, t_env e);
t_point	next_point(t_point org, t_point dest, t_point curr);
int		**get_matrix(char **argv);
double	set_x(int i, int j, t_parameters pm, t_env e);
double	set_y(int i, int j, t_parameters pm, t_env e);
void	inf(int i, int nb_line);
int	display_error(int error_code);
t_parameters	set_param(t_env e);
int	ft_isinteger(char *str);
t_point	next_point(t_point org, t_point dest, t_point curr);

#endif
