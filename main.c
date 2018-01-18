/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:07:20 by jostraye          #+#    #+#             */
/*   Updated: 2017/12/13 17:03:55 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

void	draw(t_env e)
{
	int				i;
	int				j;
	t_parameters	pm;

	pm = set_param(e);
	i = 0;
	j = 0;
	while (e.mx[i])
	{
		while (j++ <= e.mx[i][0])
			draw_grid(i, j, pm, e);
		i++;
		j = 0;
	}
}

int		expose_hook(t_env *e)
{
	draw(*e);
	return (0);
}

int		exit_win(int key_code)
{
	if (key_code == 53)
		exit(0);
	return (0);
}

t_env	init_event(t_env e)
{
	int i;

	i = 0;
	e.mlx = mlx_init();
	while (e.mx[i])
		i++;
	if (e.mx[0][0] * 10 > 2560)
		e.size_x = 2560;
	else
		e.size_x = e.mx[0][0] * 13;
	if (i * 10 > 1395)
		e.size_y = 1395;
	else
		e.size_y = i * 13;
	e.win = mlx_new_window(e.mlx, e.size_x, e.size_y, "MY GRAPH");
	return (e);
}

int		main(int ac, char **av)
{
	t_env	e;
	int		i;
	int		error_occur;

	error_occur = 0;
	i = 0;
	if (ac != 2 || open(av[1], O_RDONLY) == -1)
		error_occur = display_error(1);
	if (error_occur == 1)
		return (-1);
	if (!(e.mx = get_matrix(av)))
		error_occur = display_error(3);
	if (error_occur == 1)
		return (-1);
	e = init_event(e);
	mlx_key_hook(e.win, exit_win, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	free(e.mx);
	return (0);
}
