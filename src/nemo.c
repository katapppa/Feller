/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nemo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:32:36 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/31 18:07:25 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void		move_piece_x(t_filler *meps, t_pieces *piece)
{
	int x;
	int y;
	int flag_x;
	int i;

	flag_x = 1;
	y = 0;
	piece->real_coord_y = 0;
	while (flag_x)
	{
		x = 0;
		while (x < piece->piece_coord_x)
		{
			if (piece->piece_map[y][x] == '*')
				flag_x = 0;
			x++;
		}
		y++;
		if (flag_x == 1)
		{
			i = 0;
			while (i < piece->stars)
			{
				piece->coords_int_y[i] -= 1;
				i++;
			}
			piece->real_coord_y -= 1;
		}
	}
}

void		move_piece_y(t_filler *meps, t_pieces *piece)
{
	int y;
	int x;
	int flag_y;
	int i;

	flag_y = 1;
	x = 0;
	piece->real_coord_x = 0;
	while (flag_y)
	{
		y = 0;
		while (y < piece->piece_coord_y)
		{
			if (piece->piece_map[y][x] == '*')
				flag_y = 0;
			y++;
		}
		x++;
		if (flag_y == 1)
		{
			i = 0;
			while (i < piece->stars)
			{
				piece->coords_int_x[i] -= 1;
				i++;
			}
			piece->real_coord_x -= 1;
		}
	}
}

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
	piece->stars = i;
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
	free(line);
}

void		get_piece(t_filler *meps, t_pieces *piece)
{
	int		i;
	int		y;
	char	*line;

	i = 0;
	get_piece_info(meps, piece);
	piece->piece_map = (char**)malloc(sizeof(char*) * (piece->piece_coord_y + 1));
	while (i <= piece->piece_coord_y)
	{
		piece->piece_map[i] = (char*)malloc(sizeof(char) * (piece->piece_coord_x + 1));
		i++;
	}
	i = 0;
	y = 0;
	while (piece->piece_coord_y > y && (get_next_line(0, &line)))
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
	move_piece_y(meps, piece);
	move_piece_x(meps, piece);
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
		info->enemy = 'O';
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
