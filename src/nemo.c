/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nemo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:32:36 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/27 14:50:51 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		find_nemo_coords(t_filler *meps, t_feller *info)
{
	int x;
	int y;

	y = 0;
	if (info->player == 1)
	{
		info->me = 'O';
		info->enemy = 'X';
	}
	else
	{
		info->me = 'X';
		info->enemy = '0';
	}
	while (y < meps->coord_y)
	{
		x = 0;
		while (x < meps->coord_x)
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
			x++;
		}
		y++;
	}
}