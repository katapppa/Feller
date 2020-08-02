/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:22:05 by cgamora           #+#    #+#             */
/*   Updated: 2020/08/02 16:05:44 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		rewrite_coords_heat_map(t_feller *info, t_filler *meps)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	while (y < meps->coord_y)
	{
		x = 0;
		while (x < meps->coord_x)
		{
			if (meps->map[y][x] == info->me ||
						meps->map[y][x] == (info->me + 32))
				meps->heat_map[y][x] = -1;
			if (meps->map[y][x] == info->enemy ||
						meps->map[y][x] == (info->enemy + 32))
				meps->heat_map[y][x] = 0;
			if (meps->map[y][x] == '.')
				meps->heat_map[y][x] = real_heat_mapper(info, meps, x, y);
			x++;
		}
		y++;
	}
}

void		create_heat_map(t_feller *info, t_filler *meps)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	meps->heat_map = (int**)malloc(sizeof(int*) * (meps->coord_y + 1));
	while (i <= meps->coord_y)
	{
		meps->heat_map[i] = (int*)malloc(sizeof(int) * (meps->coord_x + 1));
		i++;
	}
	y = 0;
	while (y < meps->coord_y)
	{
		x = 0;
		while (x < meps->coord_x)
		{
			heat_map_helper(meps, info, x, y);
			x++;
		}
		y++;
	}
}

void		rewrite_map(t_filler *meps)
{
	int		y;
	int		c;
	int		x;
	char	*line;

	y = 0;
	get_next_line(0, &line);
	free(line);
	get_next_line(0, &line);
	free(line);
	while (y < meps->coord_y && (get_next_line(0, &line)))
	{
		x = 0;
		c = 4;
		while (x < meps->coord_x)
		{
			meps->map[y][x] = line[c];
			x++;
			c++;
		}
		meps->map[y][x] = '\0';
		free(line);
		y++;
	}
}

int			map_join(t_filler *meps)
{
	int		y;
	int		c;
	int		x;
	char	*line;

	y = 0;
	while (y < meps->coord_y && (get_next_line(0, &line)))
	{
		x = 0;
		c = 4;
		while (x < meps->coord_x)
		{
			meps->map[y][x] = line[c];
			x++;
			c++;
		}
		meps->map[y][x] = '\0';
		free(line);
		y++;
	}
	return (0);
}

void		get_map(t_filler *meps)
{
	int		i;
	char	*line;

	i = 0;
	meps->map = (char**)malloc(sizeof(char*) * (meps->coord_y + 1));
	while (i <= meps->coord_y)
	{
		meps->map[i] = (char*)malloc(sizeof(char) * (meps->coord_x + 1));
		i++;
	}
	get_next_line(0, &line);
	free(line);
	map_join(meps);
}
