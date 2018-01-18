/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:50:49 by jostraye          #+#    #+#             */
/*   Updated: 2017/12/13 17:06:02 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

void			inf(int i, int nb_line)
{
	ft_putstr("This is a big map, please wait ... Map is ");
	ft_putnbr((100 * i) / nb_line);
	ft_putstr("% treated\n");
	return ;
}

int				display_error(int error_code)
{
	if (error_code == 1)
	{
		ft_putstr("\nError : Please pass fdf a non-empty file:\n");
		ft_putstr("	./fdf map.fdf\n	be careful to pass 1 accessible file\n\n");
	}
	if (error_code == 3)
	{
		ft_putstr("\nError : Could not allocate map\n");
		ft_putstr("	Check for unusual data, or if file is empty\n\n");
	}
	return (1);
}

t_parameters	set_param(t_env e)
{
	t_parameters	pm;
	int				i;

	i = 0;
	while (e.mx[i])
		i++;
	pm.theta = 0.2;
	pm.iota = 0;
	pm.khapa = 0;
	pm.dph = -1;
	if (e.size_x == 2560 && e.size_y == 1395)
	{
		pm.zm = 3;
		pm.ctr.x = 0;
		pm.ctr.y = 0;
	}
	else
	{
		pm.zm = (e.size_x * e.size_y) / (16 * i * e.mx[0][0]);
		pm.ctr.x = e.size_x / pm.zm;
		pm.ctr.y = 1.7 * e.size_y / pm.zm;
	}
	return (pm);
}

int				ft_isinteger(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || ft_isalpha(str[i]) || str[i] == ' ' ||
			str[i] == ',')
			i++;
		else
			return (0);
	}
	return (1);
}
