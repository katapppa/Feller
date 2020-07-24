/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:24:35 by cgamora           #+#    #+#             */
/*   Updated: 2019/11/02 20:11:48 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			prov_ost(char **ost, char **line)
{
	char			*fn;
	char			*tmp;
	int				i;

	i = 0;
	tmp = *ost;
	if ((fn = ft_strchr(tmp, '\n')))
	{
		while (tmp[i] != '\n')
			i++;
		*line = ft_strsub(tmp, 0, i);
		*ost = ft_strdup(fn + 1);
		free(tmp);
		tmp = NULL;
	}
	else
	{
		*line = ft_strdup(*ost);
		ft_strclr(*ost);
	}
	return (1);
}

int			get(const int fd, char **line, char **ost)
{
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				rb;

	while ((rb = read(fd, buf, BUFF_SIZE)))
	{
		buf[rb] = '\0';
		if (!*ost)
			*ost = ft_strnew(0);
		tmp = *ost;
		*ost = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (rb < 0)
		return (-1);
	else if (rb == 0 && (*ost == NULL || *ost[0] == '\0'))
		return (0);
	return (prov_ost(ost, line));
}

t_lest		*create(int fd)
{
	t_lest			*new;

	new = (t_lest*)malloc(sizeof(t_lest));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->ost = NULL;
	new->next = NULL;
	return (new);
}

int			get_next_line(const int fd, char **line)
{
	static t_lest	*head;
	t_lest			*tmp;
	char			*buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || BUFF_SIZE < 1 || (read(fd, buf, 0) < 0))
		return (-1);
	if (head == NULL)
		head = create(fd);
	if (head == NULL)
		return (-1);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = create(fd);
		tmp = tmp->next;
	}
	return (get(tmp->fd, line, &tmp->ost));
}
