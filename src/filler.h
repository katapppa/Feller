/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:00:00 by cgamora           #+#    #+#             */
/*   Updated: 2020/08/02 16:52:25 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef	struct	s_filler
{
	int			coord_x;
	int			coord_y;
	char		**map;
	int			**heat_map;
}				t_filler;

typedef	struct	s_feller
{
	int			player;
	char		enemy;
	char		me;
	int			me_x;
	int			me_y;
	int			enemy_x;
	int			enemy_y;
}				t_feller;

typedef	struct	s_helper
{
	int			min_sum;
	int			sdvig_x;
	int			sdvig_y;
}				t_helper;

typedef	struct	s_pieces
{
	int			piece_coord_x;
	int			piece_coord_y;
	char		**piece_map;
	int			smesh_x;
	int			smesh_y;
	int			*coords_int_x;
	int			*coords_int_y;
	int			stars;
	int			real_coord_x;
	int			real_coord_y;
}				t_pieces;

void			get_map(t_filler *meps);
void			find_nemo_coords(t_filler *meps, t_feller *info);
void			create_heat_map(t_feller *info, t_filler *meps);
void			get_piece(t_pieces *piece);
int				piece_placer(t_filler *meps, t_pieces *piece);
void			rewrite_coords_heat_map(t_feller *info, t_filler *meps);
void			rewrite_map(t_filler *meps);
void			free_piece(t_pieces *piece);
void			init_game(t_feller *info, t_filler *meps, t_pieces *piece);
void			get_player(t_feller *info);
int				get_coords(t_filler *meps);
void			last_word(void);
void			draw_result(t_helper *alg, t_pieces *piece);
int				mod(int x);
int				real_heat_mapper(t_feller *info, t_filler *meps, int x, int y);
void			heat_map_helper(t_filler *meps, t_feller *info, int x, int y);
void			nemo_helper(t_feller *info, t_filler *meps, int x, int y);
void			stars_coords(t_pieces *piece);
int				piece_info(char *line, t_pieces *piece, int i);
void			get_piece_map(t_pieces *piece);
void			edit_piece(t_pieces *piece);
void			piece_move_x(t_pieces *piece);
void			piece_move_y(t_pieces *piece);

#endif
