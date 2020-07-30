/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:42:54 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/30 16:49:26 by cgamora          ###   ########.fr       */
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
	// return (0);
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
	//printf("PLAYER NUMBER IS: %d\n", info->player);
	get_coords(meps);
	//printf("MAPS COORDS IS: Y:%d AND X:%d\n", meps->coord_y, meps->coord_x);
	get_map(meps);
	//printf("MAPS WAS GETTERxDDD\n");
	find_nemo_coords(meps, info);
	//printf("enemy %d and %d\n", info->enemy_x, info->enemy_y);
	//printf("me %d and %d\n", info->me_x, info->me_y);
	create_heat_map(info, meps);	
	// int x;
	// int y;

	// x = 0;
	// y = 0;
	// while (y < meps->coord_y)
	// {
	// 	x = 0;
	// 	while (x < meps->coord_x)
	// 	{
	// 		//printf("%3d", meps->heat_map[y][x]);
	// 		x++;
	// 	}
	// 	printf("\n");
	// 	y++;
	// }
	get_piece(meps, piece);
	//printf("COORD OF PIECE IS: %d AND %d", piece->piece_coord_y, piece->piece_coord_x);
	piece_placer(meps, piece, info);
	//x = 0;
	// while (x < meps->coord_y)
	// {
	// 	printf("%s\n", meps->map[x]);
	// 	x++;
	// }
	// printf("END OF INIT\n");
	int shet;

	shet = 1;
	while (shet)
	{
		rewrite_map(meps);
		//printf("MAPS WAS GETTERxDDD\n");
		//printf("enemy %d and %d\n", info->enemy_x, info->enemy_y);
		//printf("me %d and %d\n", info->me_x, info->me_y);
		rewrite_heat_map(info, meps);
		// int x;
		// int y;

		// x = 0;
		// y = 0;
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
		//printf("COORD OF PIECE IS: %d AND %d", piece->piece_coord_y, piece->piece_coord_x);
		// x = 0;
		// while (x < piece->piece_coord_y)
		// {
		// 	printf("%s\n", piece->piece_map[x]);
		// 	x++;
		// }
		// x = 0;
		// y = 0;
		// while (y < 2)
		// {
		// 	printf("%d  ", piece->coords_int_y[y]);
		// 	y++;
		// }
		// printf("\n");
		// while (x < 2)
		// {
		// 	printf("%d  ", piece->coords_int_x[x]);
		// 	x++;
		// }
		// printf("\n");
		shet = piece_placer(meps, piece, info);
		//x = 0;
		// while (x < meps->coord_y)
		// {
		// 	printf("%s\n", meps->map[x]);
		// 	x++;
		// }
		// while (x <= piece->piece_coord_y)
		// {
		// 	free(piece->piece_map[x]);
		// 	x++;
		// }
		// free(piece->coords_int_x);
		// free(piece->coords_int_y);
		// free(piece->piece_map);
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
	return 0;
}