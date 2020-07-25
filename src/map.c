/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:22:05 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/25 18:27:38 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int		map_join(t_filler *meps)
{
	int		y;
	int		c;
	int		x;
	char	*line;

	y = 0;
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
		printf("%d\n", y);
	}
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
