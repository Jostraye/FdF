/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:32:33 by jostraye          #+#    #+#             */
/*   Updated: 2017/12/13 17:01:02 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

void	slope_draw(t_point org, t_point dest, t_env e)
{
	int		sign;
	t_point	curr;

	sign = ft_sign(dest.y - org.y);
	curr = org;
	while (curr.x != dest.x + 1 && curr.y != sign * dest.y + sign)
	{
		mlx_pixel_put(e.mlx, e.win, curr.x, curr.y, 0xFFFFFF);
		if (curr.x == dest.x && curr.y == sign * dest.y)
			break ;
		curr = next_point(org, dest, curr);
	}
	return ;
}

void	horizontal_draw(t_point fr, t_point to, t_env e)
{
	if (fr.y < to.y)
		while (fr.y++ != to.y)
			mlx_pixel_put(e.mlx, e.win, fr.x, fr.y, 0xFFFFFF);
	else
		while (fr.y-- != to.y)
			mlx_pixel_put(e.mlx, e.win, to.x, to.y, 0xFFFFFF);
}

void	vertical_draw(t_point fr, t_point to, t_env e)
{
	if (fr.x < to.x)
		while (fr.x++ != to.x)
			mlx_pixel_put(e.mlx, e.win, fr.x, fr.y, 0xFFFFFF);
	else
		while (fr.x-- != to.x)
			mlx_pixel_put(e.mlx, e.win, to.x, to.y, 0xFFFFFF);
}

void	draw_line(t_point fr, t_point to, t_env e)
{
	int diviseur;

	diviseur = (to.x - fr.x);
	if (diviseur == 0)
		horizontal_draw(fr, to, e);
	else if (fr.y == to.y)
		vertical_draw(fr, to, e);
	else if (diviseur < 0)
		slope_draw(to, fr, e);
	else if (diviseur > 0)
		slope_draw(fr, to, e);
	return ;
}

void	draw_grid(int i, int j, t_parameters pm, t_env e)
{
	pm.fr.x = round(set_x(i, j, pm, e));
	pm.fr.y = round(set_y(i, j, pm, e));
	j++;
	pm.to.x = round(set_x(i, j, pm, e));
	pm.to.y = round(set_y(i, j, pm, e));
	if (j <= e.mx[i][0])
		draw_line(pm.fr, pm.to, e);
	i++;
	j--;
	if (e.mx[i] && j <= e.mx[i][0])
	{
		pm.to.x = round(set_x(i, j, pm, e));
		pm.to.y = round(set_y(i, j, pm, e));
		draw_line(pm.fr, pm.to, e);
	}
}
