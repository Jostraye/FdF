/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:52:01 by jostraye          #+#    #+#             */
/*   Updated: 2017/12/13 17:01:16 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

double	set_x(int i, int j, t_parameters pm, t_env e)
{
	double coordinate;

	coordinate = pm.zm * (cos(pm.theta) * j + sin(pm.theta) * i)
	- e.mx[i][j] * pm.dph
	+ pm.ctr.x;
	return (coordinate);
}

double	set_y(int i, int j, t_parameters pm, t_env e)
{
	double coordinate;

	coordinate = pm.zm * (cos(pm.theta) * i - sin(pm.theta) * j)
	- e.mx[i][j] * pm.dph
	+ pm.ctr.y;
	return (coordinate);
}

t_point	next_point(t_point org, t_point dest, t_point curr)
{
	t_point	next;
	t_line	line;

	line.diviseur = (dest.x - org.x);
	line.ordonnee = ((org.y * dest.x) - (dest.y * org.x));
	line.pente = (dest.y - org.y);
	line.sign = ft_sign(line.pente);
	next.y = ((line.pente * (curr.x)) + line.ordonnee);
	if (dest.y > org.y)
	{
		if (next.y >= line.diviseur * (curr.y))
			curr.y++;
		else if (next.y < line.diviseur * (curr.y))
			curr.x++;
	}
	if (dest.y < org.y)
	{
		if (next.y <= line.diviseur * (curr.y))
			curr.y--;
		else if (next.y > line.diviseur * (curr.y))
			curr.x++;
	}
	return (curr);
}
