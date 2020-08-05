/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:42:54 by cgamora           #+#    #+#             */
/*   Updated: 2020/08/04 14:21:33 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	if (!(get_next_line(0, &line)))
		ft_exit(0);
	get_it(line, meps);
	free(line);
	return (1);
}

void		get_player(t_feller *info)
{
	char	*line;

	info->player = 0;
	if (!(get_next_line(0, &line)))
		ft_exit(0);
	if (ft_strstr(line, "p1"))
		info->player = 1;
	else
		info->player = 2;
	free(line);
}

void		free_end(t_pieces *piece, t_filler *meps, t_feller *info)
{
	int x;

	x = 0;
	last_word();
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
}

int			main(void)
{
	t_filler	*meps;
	t_feller	*info;
	t_pieces	*piece;
	int			shet;

	if (!(piece = (t_pieces*)malloc(sizeof(t_pieces))))
		return (0);
	if (!(meps = (t_filler*)malloc(sizeof(t_filler))))
		return (0);
	if (!(info = (t_feller*)malloc(sizeof(t_feller))))
		return (0);
	shet = 1;
	init_game(info, meps, piece);
	piece_placer(meps, piece);
	free_piece(piece);
	while (shet)
	{
		rewrite_map(meps);
		rewrite_coords_heat_map(info, meps);
		get_piece(piece);
		shet = piece_placer(meps, piece);
		free_piece(piece);
	}
	free_end(piece, meps, info);
	return (1);
}
