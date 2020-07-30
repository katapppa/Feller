/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:00:00 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/30 16:42:40 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "../libft/libft.h"
#include "../libft/get_next_line.h"

typedef		struct	s_filler //meps
{
	int		coord_x;
	int		coord_y;
	char	**map;
	int		**heat_map;
}					t_filler;

typedef		struct	s_feller //info
{
	int		player;
	char	enemy;
	char	me;
	int		me_x;
	int		me_y;
	int		enemy_x;
	int		enemy_y;
}					t_feller;

typedef		struct	s_helper //alg
{
	int		min_sum;
	int		sdvig_x;
	int		sdvig_y;
}					t_helper;

typedef		struct	s_pieces //piece
{
	int		piece_coord_x;
	int		piece_coord_y;
	char	**piece_map;
	int		smesh_x;
	int		smesh_y;
	int		*coords_int_x;
	int		*coords_int_y;
	int		stars;
}					t_pieces;



void        get_map(t_filler *meps);
void		find_nemo_coords(t_filler *meps, t_feller *info);
void		create_heat_map(t_feller *info, t_filler *meps);
void		get_piece(t_filler *meps, t_pieces *piece);
int			piece_placer(t_filler *meps, t_pieces *piece, t_feller *info);
void		rewrite_heat_map(t_feller *info, t_filler *meps);
void		rewrite_map(t_filler *meps);

#endif