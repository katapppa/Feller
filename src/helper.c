/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 17:36:43 by cgamora           #+#    #+#             */
/*   Updated: 2020/08/04 13:47:57 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		free_piece(t_pieces *piece)
{
	int x;

	x = 0;
	while (x <= piece->piece_coord_y)
	{
		ft_memdel((void**)&(piece->piece_map[x]));
		x++;
	}
	ft_memdel((void**)&(piece->coords_int_x));
	ft_memdel((void**)&(piece->coords_int_y));
	ft_memdel((void**)&(piece->piece_map));
}

void		init_game(t_feller *info, t_filler *meps, t_pieces *piece)
{
	get_player(info);
	get_coords(meps);
	get_map(meps);
	find_nemo_coords(meps, info);
	create_heat_map(info, meps);
	get_piece(piece);
}

void		last_word(void)
{
	ft_putnbr(0);
	ft_putchar(' ');
	ft_putnbr(0);
	ft_putchar('\n');
}

void		draw_result(t_helper *alg, t_pieces *piece)
{
	ft_putnbr(alg->sdvig_y + piece->real_coord_y);
	ft_putchar(' ');
	ft_putnbr(alg->sdvig_x + piece->real_coord_x);
	ft_putchar('\n');
}

int			mod(int x)
{
	if (x >= 0)
		return (x);
	else
		return (-x);
}
