/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nemo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:32:36 by cgamora           #+#    #+#             */
/*   Updated: 2020/08/04 14:08:41 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		move_piece_x(t_pieces *piece)
{
	int x;
	int y;
	int flag_x;

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
			piece_move_y(piece);
	}
}

void		move_piece_y(t_pieces *piece)
{
	int y;
	int x;
	int flag_y;

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
			piece_move_x(piece);
	}
}

void		get_piece_info(t_pieces *piece)
{
	int		i;
	char	*line;

	if (!(get_next_line(0, &line)))
		ft_exit(0);
	i = 0;
	piece->piece_coord_x = 0;
	piece->piece_coord_y = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			i = piece_info(line, piece, i);
		i++;
	}
	free(line);
}

void		get_piece(t_pieces *piece)
{
	int		i;

	i = 0;
	get_piece_info(piece);
	if (!(piece->piece_map = (char**)malloc(sizeof(char*) *
				(piece->piece_coord_y + 1))))
		ft_exit(0);
	while (i <= piece->piece_coord_y)
	{
		if (!(piece->piece_map[i] = (char*)malloc(sizeof(char) *
				(piece->piece_coord_x + 1))))
			ft_exit(0);
		i++;
	}
	get_piece_map(piece);
	edit_piece(piece);
	move_piece_y(piece);
	move_piece_x(piece);
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
			nemo_helper(info, meps, x, y);
			x++;
		}
		y++;
	}
}
