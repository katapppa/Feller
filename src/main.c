/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:42:54 by cgamora           #+#    #+#             */
/*   Updated: 2020/08/01 13:49:13 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void		get_it(char *line, t_filler *meps)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]))
		{
			while (line[i] != ' ')
			{
				meps->coord_y += (line[i] - 48);
				if (meps->coord_y != 0 && line[i + 1] != ' ')
					meps->coord_y *= 10;
				i++;
			}
			i++;
			while (ft_isdigit(line[i]))
			{
				meps->coord_x += (line[i] - 48);
				if (meps->coord_x != 0 && line[i + 1] != ':')
					meps->coord_x *= 10;
				i++;
			}
		}
		i++;
	}
}

int			get_coords(t_filler *meps)
{
	char	*line;

	meps->coord_y = 0;
	meps->coord_x = 0;
	get_next_line(0, &line);
	get_it(line, meps);
	free(line);
	return (1);
}

void		get_player(t_feller *info)
{
	char	*line;

	info->player = 0;
	if (get_next_line(0, &line))
	{
		if (ft_strstr(line, "p1"))
			info->player = 1;
		if (ft_strstr(line, "p2"))
			info->player = 2;
	}
	free(line);
}

void		free_end(t_pieces *piece, t_filler *meps, t_feller *info)
{
	int x;

	x = 0;
	//free(piece);
	ft_memdel((void**)&piece);
	while (x <= meps->coord_y)
	{
		// free(meps->heat_map[x]);
		// free(meps->map[x]);
		ft_memdel((void**)&(meps->heat_map[x]));
		ft_memdel((void**)&(meps->map[x]));
		x++;
	}
	// free(meps->map);
	// free(meps->heat_map);
	// free(meps);
	// free(info);
	ft_memdel((void**)&(meps->map));
	ft_memdel((void**)&(meps->heat_map));
	ft_memdel((void**)&(meps));
	ft_memdel((void**)&(info));
}

int			main(void)
{
	t_filler	*meps;
	t_feller	*info;
	t_pieces	*piece;
	int			shet;

	piece = (t_pieces*)malloc(sizeof(t_pieces));
	meps = (t_filler*)malloc(sizeof(t_filler));
	info = (t_feller*)malloc(sizeof(t_feller));
	init_game(info, meps, piece);
	piece_placer(meps, piece, info);
	shet = 1;
	free_piece(piece);
	while (shet)
	{
		rewrite_map(meps);
		rewrite_coords_heat_map(info, meps);
		// int x = 0;
		// int y = 0;

		// while (y < meps->coord_y)
		// {
		// 	x = 0;
		// 	while (x < meps->coord_x)
		// 	{
		// 		printf("%3d", meps->heat_map[y][x]);
		// 		x++;
		// 	}
		// 	printf("\n");
		// 	y++;
		// }
		get_piece(meps, piece);
		// x = 0;
		// printf("\n");
		// while (x < piece->piece_coord_y)
		// {
		// 	printf("%s\n", piece->piece_map[x]);
		// 	x++;
		// }
		// y = 0;
		// while (y < piece->stars)
		// {
		// 	printf("Y IS %d AND X IS %d\n", piece->coords_int_y[y], piece->coords_int_x[y]);
		// 	y++;
		// }
		shet = piece_placer(meps, piece, info);
		free_piece(piece);
	}
	//printf("%d %d\n",0, 0);
	free_end(piece, meps, info);
	//printf("the end\n");
	return (0);
}
