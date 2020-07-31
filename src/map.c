/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:22:05 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/31 16:36:45 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		mod(int x)
{
	if (x >= 0)
		return (x);
	else
		return (-x);	
}

int		real_heat_mapper(t_feller *info, t_filler *meps, int x, int y)
{
	int i;
	int j;
	int min;
	int dist;

	j = 0;
	dist = 0;
	min = -3;
	while (j < meps->coord_y)
	{
		i = 0;
		while (i < meps->coord_x)
		{
			if (meps->map[j][i] == info->enemy)
			{
				dist = (mod(y - j) + mod(x - i));
				if (min == -3)
					min = dist;
				if (dist < min)
					min = dist;
			}
			i++;
		}
		j++;
	}
	return (min);
}

/*void	rewrite_het_map(t_feller *info, t_filler *meps)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while ()
	{
		while ()
		{

		}
	}
}*/

void	rewrite_coords_heat_map(t_feller *info, t_filler *meps)
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
			if (meps->map[y][x] == info->me)
				meps->heat_map[y][x] = -1;
			if (meps->map[y][x] == info->enemy/* || meps->map[y][x] == (info->enemy) + 32*/)
				meps->heat_map[y][x] = 0;
			if (meps->map[y][x] == '.')
				meps->heat_map[y][x] = real_heat_mapper(info, meps, x, y);
			x++;
		}
		y++;
	}
}

void	create_heat_map(t_feller *info, t_filler *meps)
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
			if (meps->map[y][x] == '.')
				meps->heat_map[y][x] = (mod(y - info->enemy_y) + mod(x - info->enemy_x));
			if (meps->map[y][x] == info->enemy)
				meps->heat_map[y][x] = 0;
			if (meps->map[y][x] == info->me)
				meps->heat_map[y][x] = -1;
			x++;
		}
		y++;
	}
}

void	rewrite_map(t_filler *meps)
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
		while (line[c])
		{
			meps->map[y][x] = line[c];
			x++;
			c++;
		}
		free(line);
		//meps->map[y][x] = '\0';
		y++;
	}
	//free(line);
}

int		map_join(t_filler *meps)
{
	int		y;
	int		c;
	int		x;
	char	*line;

	y = 0;
	while (y < meps->coord_y  && (get_next_line(0, &line)))
	{
		x = 0;
		c = 4;
		while (line[c])
		{
			meps->map[y][x] = line[c];
			x++;
			c++;
		}
		free(line);
		//meps->map[y][x] = '\0';
		y++;
	}
	//free(line);
	return (0);
}

void        get_map(t_filler *meps)
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
