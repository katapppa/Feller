/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 17:36:43 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/31 18:04:07 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		free_piece(t_pieces *piece)
{
	int x;

	x = 0;
	while (x <= piece->piece_coord_y)
	{
		free(piece->piece_map[x]);
		x++;
	}
	free(piece->coords_int_x);
	free(piece->coords_int_y);
	free(piece->piece_map);
}

void		init_game(t_feller *info, t_filler *meps, t_pieces *piece)
{
	get_player(info);
	get_coords(meps);
	get_map(meps);
	find_nemo_coords(meps, info);
	create_heat_map(info, meps);
	get_piece(meps, piece);
}
