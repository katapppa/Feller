/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nemo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:32:36 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/27 18:03:00 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void		edit_piece(t_filler *meps, t_pieces *piece)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (piece->piece_coord_y > y)
	{
		x = 0;
		while (x < piece->piece_coord_x)
		{
			if (piece->piece_map[y][x] == '*')
				i++;
			x++;
		}
		y++;
	}
	printf("KOL-VO STARS IS: %d\n", i);
	piece->coords_int_x = (int*)malloc(sizeof(int) * i);
	piece->coords_int_y = (int*)malloc(sizeof(int) * i);
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

void		get_piece_info(t_filler *meps, t_pieces *piece)
{
	int		i;
	char	*line;

	get_next_line(0, &line);
	i = 0;
	piece->piece_coord_x = 0;
	piece->piece_coord_y = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]))
		{
			while (line[i] != ' ')
			{
				piece->piece_coord_y += (line[i] - 48);
				if (piece->piece_coord_y != 0 && line[i + 1] != ' ')
					piece->piece_coord_y *= 10;
				i++;
			}
			i++;
			while (ft_isdigit(line[i]))
			{
				piece->piece_coord_x += (line[i] - 48);
				if (piece->piece_coord_x != 0 && line[i + 1] != ':')
					piece->piece_coord_x *= 10;
				i++;
			}
		}
		i++;
	}
	printf("Piece coords is: %d and %d\n", piece->piece_coord_x, piece->piece_coord_y);
	free(line);
}

void		get_piece(t_filler *meps, t_pieces *piece)
{
	int i;
	int y;
	char *line;

	i = 0;
	get_piece_info(meps, piece);
	piece->piece_map = (char**)malloc(sizeof(char*) * (piece->piece_coord_y));
    while (i < piece->piece_coord_x)
    {
        piece->piece_map[i] = (char*)malloc(sizeof(char) * (piece->piece_coord_x + 1));
        i++;
    }
	i = 0;
	y = 0;
	while ((get_next_line(0, &line)) && piece->piece_coord_y > y)
	{
		i = 0;
		while (line[i])
		{
			piece->piece_map[y][i] = line[i];
			i++;
		}
		y++;
		free(line);
	}
	edit_piece(meps, piece);
}

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