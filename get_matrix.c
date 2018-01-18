/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:22:29 by jostraye          #+#    #+#             */
/*   Updated: 2017/12/13 16:57:27 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	get_nb_line(char *file_name)
{
	int		fd;
	int		ret;
	int		nb_line;
	int		i;
	char	buf[BUFF_SIZE + 1];

	i = 0;
	nb_line = 0;
	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (0);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret + 1] = '\0';
		while (buf[i])
		{
			if (buf[i] == '\n')
				nb_line++;
			i++;
		}
		i = 0;
	}
	return (nb_line);
}

int	get_nb_points(char *line)
{
	int nb_points;
	int	nombre;

	nb_points = 0;
	nombre = 0;
	while (line[0])
	{
		if (line[0] && line[0] != ' ' && !nombre)
		{
			nombre = 1;
			nb_points++;
		}
		else if (line[0] && line[0] == ' ')
			nombre = 0;
		line++;
	}
	return (nb_points);
}

int	*attribute_point(int i, char *str, int *tab_points, int nbl)
{
	int	j;
	int	nbc;

	nbc = get_nb_points(str);
	j = 1;
	while (str[0] != '\0')
	{
		while (str && str[0] == ' ')
			str++;
		if (ft_isinteger(str))
			tab_points[j] = ft_atoi(str);
		else
			return (NULL);
		if ((i * j) % (nbl * nbc / 10) == 0 && i * j != 0 && j % (nbc) == 0)
			inf(i, nbl);
		while (str[0] != '\0' && str[0] != ' ')
			str++;
		j++;
	}
	return (tab_points);
}

int	**attribute_matrix(int nbl, int **tab_points, int fd)
{
	int		i;
	char	*str;
	int		nbc;

	i = 0;
	while (get_next_line(fd, &str))
	{
		nbc = get_nb_points(str);
		tab_points[i] = malloc(sizeof(int) * (nbc + 1));
		tab_points[i][0] = nbc;
		if (!(tab_points[i] = attribute_point(i, str, tab_points[i], nbl)))
			return (NULL);
		i++;
	}
	return (tab_points);
}

int	**get_matrix(char **argv)
{
	int			fd;
	int			nb_line;
	int			**tab_points;

	if ((nb_line = get_nb_line(argv[1])) == 0)
		return (NULL);
	if (!(tab_points = malloc(sizeof(int*) * (nb_line + 1))))
		return (NULL);
	tab_points[nb_line] = NULL;
	if ((fd = open(argv[1], O_RDONLY)) >= 0 && nb_line > 0)
	{
		tab_points = attribute_matrix(nb_line, tab_points, fd);
	}
	return (tab_points);
}
