/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:42:54 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/31 16:36:50 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void	get_it(char *line, t_filler *meps)
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

int		get_coords(t_filler *meps)
{
	char *line;	

	meps->coord_y = 0;
	meps->coord_x = 0;
	// while (get_next_line(0, &line))
	// {
	// 	if (ft_strstr(line, "Plateau"))
	// 	{
	// 		get_it(line, meps);
	// 		free(line);
	// 		return (1);
	// 	}
	// 	free(line);
	// }
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

int			main(void)
{
    t_filler	*meps;
	t_feller	*info;
	t_pieces	*piece;

	piece = (t_pieces*)malloc(sizeof(t_pieces));
    meps = (t_filler*)malloc(sizeof(t_filler));
	info = (t_feller*)malloc(sizeof(t_feller));

    get_player(info);
	get_coords(meps);
	get_map(meps);
	find_nemo_coords(meps, info);
	create_heat_map(info, meps);	
	get_piece(meps, piece);
	piece_placer(meps, piece, info);
	int shet;
	int x;

	shet = 1;
	x = 0;
	while (x <= piece->piece_coord_y)
	{
		free(piece->piece_map[x]);
		x++;
	}
	free(piece->coords_int_x);
	free(piece->coords_int_y);
	free(piece->piece_map);
	while (shet != 2)
	{
		rewrite_map(meps);
		rewrite_coords_heat_map(info, meps);
		get_piece(meps, piece);
		piece_placer(meps, piece, info);
		//shet = piece_placer(meps, piece, info);
		x = 0;
		while (x <= piece->piece_coord_y)
		{
			free(piece->piece_map[x]);
			x++;
		}
		free(piece->coords_int_x);
		free(piece->coords_int_y);
		free(piece->piece_map);
		shet++;
		// free(piece);
		// x = 0;
		// while (x <= meps->coord_y)
		// {
		// 	free(meps->map[x]);
		// 	x++;
		// }
		//free(meps->map);
		// free(meps);
	}
	x = 0;
	free(piece);
	while (x <= meps->coord_y)
	{
		free(meps->heat_map[x]);
		free(meps->map[x]);
		x++;
	}
	free(meps->map);
	free(meps->heat_map);
	free(meps);
	free(info);
	return 0; //1368
}