/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:22:05 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/27 15:46:38 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int		mod(int x)
{
	if (x >= 0)
		return (x);
	else
		return (-x);	
}

void	create_heat_map(t_feller *info, t_filler *meps)
{
	int		x;
	int		y;
	int		i;

	i = 0;
    meps->heat_map = (int**)malloc(sizeof(int*) * (meps->coord_y));
    while (i < meps->coord_x)
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
			if (meps->map[y][x] == 'X')
				meps->heat_map[y][x] = 0;
			if (meps->map[y][x] == 'O')
				meps->heat_map[y][x] = -1;
			x++;
		}
		y++;
	}
}

int		map_join(t_filler *meps)
{
	int		y;
	int		c;
	int		x;
	char	*line;

	y = 0;
	printf("%d\n", meps->coord_y);
	while ((get_next_line(0, &line)) && y < meps->coord_y)
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
		meps->map[y][x] = '\0';
		y++;
	}
	free(line);
	return (0);
}

void        get_map(t_filler *meps)
{
    int		i;
    char	*line;

    i = 0;
    meps->map = (char**)malloc(sizeof(char*) * (meps->coord_y));
    while (i <= meps->coord_x)
    {
        meps->map[i] = (char*)malloc(sizeof(char) * meps->coord_x + 1);
        i++;
    }
    get_next_line(0, &line);
    free(line);
	printf("start map\n");
	map_join(meps);
}
