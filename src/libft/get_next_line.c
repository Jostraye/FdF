/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:43:38 by jostraye          #+#    #+#             */
/*   Updated: 2017/11/28 17:01:49 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char			*ft_strjoin_until(char const *s1, char c)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (!s1 || !c)
		return (NULL);
	size = ft_strlen(s1);
	str = ft_strnew(size + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < size)
		str[i] = s1[i];
	str[i] = c;
	return (str);
}

int				ft_copy_until(char **dst, char *src)
{
	int	i;
	int	count;
	int	pos;

	i = -1;
	count = 0;
	while (src[++i])
		if (src[i] == '\n')
			break ;
	pos = i;
	if (!(*dst = ft_strnew(i)))
		return (0);
	while (src[count] && count < i)
	{
		if (!(*dst = ft_strjoin_until(*dst, src[count])))
			return (0);
		count++;
	}
	return (pos);
}

static t_list	*correct_file(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*file;
	int				i;
	int				ret;
	t_list			*curr;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		|| !(*line = ft_strnew(1)))
		return (-1);
	curr = correct_file(&file, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		curr->content = ft_strjoin(curr->content, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !(ft_strlen(curr->content)))
		return (0);
	i = ft_copy_until(line, curr->content);
	if (i == (int)ft_strlen(curr->content))
		ft_strclr(curr->content);
	else
		curr->content = curr->content + (i + 1);
	return (1);
}
