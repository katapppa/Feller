/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 13:45:16 by cgamora           #+#    #+#             */
/*   Updated: 2020/08/04 14:10:15 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		miss_some_str(int y)
{
	char *line;

	y = 322;
	if (!(get_next_line(0, &line)))
		ft_exit(0);
	free(line);
	if (!(get_next_line(0, &line)))
		ft_exit(0);
	free(line);
}

void		ft_exit(int i)
{
	perror("ERROR!");
	exit(i);
}
