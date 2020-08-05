/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:19:00 by cgamora           #+#    #+#             */
/*   Updated: 2020/08/04 14:06:53 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		piece_move_x(t_pieces *piece)
{
	int i;

	i = 0;
	while (i < piece->stars)
	{
		piece->coords_int_x[i] -= 1;
		i++;
	}
	piece->real_coord_x -= 1;
}

void		piece_move_y(t_pieces *piece)
{
	int i;

	i = 0;
	while (i < piece->stars)
	{
		piece->coords_int_y[i] -= 1;
		i++;
	}
	piece->real_coord_y -= 1;
}

void		edit_piece(t_pieces *piece)
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
	if (!(piece->coords_int_x = (int*)malloc(sizeof(int) * i)))
		ft_exit(0);
	if (!(piece->coords_int_y = (int*)malloc(sizeof(int) * i)))
		ft_exit(0);
	stars_coords(piece);
}

void		get_piece_map(t_pieces *piece)
{
	int		i;
	int		y;
	char	*line;

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
		piece->piece_map[y][i] = '\0';
		y++;
		free(line);
	}
}

int			piece_info(char *line, t_pieces *piece, int i)
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
	return (i);
}
