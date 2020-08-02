/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:54:40 by cgamora           #+#    #+#             */
/*   Updated: 2020/08/02 16:16:31 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		stars_coords(t_pieces *piece)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	while (piece->piece_coord_y > y)
	{
		x = 0;
		while (x < piece->piece_coord_x)
		{
			if (piece->piece_map[y][x] == '*')
			{
				piece->coords_int_x[i] = x;
				piece->coords_int_y[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

void		nemo_helper(t_feller *info, t_filler *meps, int x, int y)
{
	if (meps->map[y][x] == 'O' && info->me == 'O')
	{
		info->me_x = x;
		info->me_y = y;
	}
	if (meps->map[y][x] == 'X' && info->me == 'X')
	{
		info->me_x = x;
		info->me_y = y;
	}
	if (meps->map[y][x] == 'X' && info->enemy == 'X')
	{
		info->enemy_x = x;
		info->enemy_y = y;
	}
	if (meps->map[y][x] == 'O' && info->enemy == 'O')
	{
		info->enemy_x = x;
		info->enemy_y = y;
	}
}

void		heat_map_helper(t_filler *meps, t_feller *info, int x, int y)
{
	if (meps->map[y][x] == '.')
		meps->heat_map[y][x] =
			(mod(y - info->enemy_y) + mod(x - info->enemy_x));
	if (meps->map[y][x] == info->enemy)
		meps->heat_map[y][x] = 0;
	if (meps->map[y][x] == info->me)
		meps->heat_map[y][x] = -1;
}

int			majic(int min, int dist)
{
	if (min == -3)
		min = dist;
	if (dist < min)
		min = dist;
	return (min);
}

int			real_heat_mapper(t_feller *info, t_filler *meps, int x, int y)
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
			if (meps->map[j][i] == info->enemy || meps->map[j][i]
							== (info->enemy + 32))
			{
				dist = (mod(y - j) + mod(x - i));
				min = majic(min, dist);
			}
			i++;
		}
		j++;
	}
	return (min);
}
