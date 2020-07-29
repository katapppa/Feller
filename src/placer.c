/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 16:58:02 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/29 14:00:03 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void		draw_result(t_helper *alg, t_filler *meps, t_pieces *piece, t_feller *info)
{
	int i;

	i = 0;
	while (i < piece->stars)
	{
		meps->map[piece->coords_int_y[i] + alg->sdvig_y][piece->coords_int_x[i] + alg->sdvig_x] = info->me;
		i++;
	}
}

void		alg_get_info(t_filler *meps, t_pieces *piece, t_helper *alg, t_feller *info)
{
	int i;
	int min;
	
	i = 0;
	min = 0;
	while (i < piece->stars)
	{
		if (meps->heat_map[piece->coords_int_y[i] + piece->smesh_y][piece->coords_int_x[i] + piece->smesh_x] == info->me)
			i++;
		min += meps->heat_map[piece->coords_int_y[i] + piece->smesh_y][piece->coords_int_x[i] + piece->smesh_x];
		i++; 
	}
	if (alg->min_sum == -3)
	{
		alg->min_sum = min;
		alg->sdvig_x = piece->smesh_x;
		alg->sdvig_y = piece->smesh_y;
	}
	else if (alg->min_sum > min)
	{
		alg->min_sum = min;
		alg->sdvig_x = piece->smesh_x;
		alg->sdvig_y = piece->smesh_y;
	}
}

int			rules_check_y(t_filler *meps, t_pieces *piece)
{
	int i;

	i = 0;
	while (i < piece->stars)
	{
		if ((piece->coords_int_y[i] + piece->smesh_y) >= meps->coord_y)
			return (0);			
		i++;
	}
	return (1);
}

int			rules_check_x(t_filler *meps, t_pieces *piece)
{
	int i;

	i = 0;
	while (i < piece->stars)
	{
		if ((piece->coords_int_x[i] + piece->smesh_x) >= meps->coord_x)
			return (0);			
		i++;
	}
	return (1);
}

int			rules_check(t_filler *meps, t_pieces *piece, t_feller *info)
{
	int i;
	int	flag;
	int	point; 

	i = 0;
	flag = 0;
	while (i < piece->stars)
	{
		if (meps->heat_map[piece->coords_int_y[i] + piece->smesh_y][piece->coords_int_x[i] + piece->smesh_x] == -1)
			flag++;
		if (meps->heat_map[piece->coords_int_y[i] + piece->smesh_y][piece->coords_int_x[i] + piece->smesh_x] == 0)
			return (0);
		i++;
	}
	if (flag != 1)
		return (0);
	return (1);
}

void		piece_placer(t_filler *meps, t_pieces *piece, t_feller *info)
{
	t_helper	*alg;

	alg = (t_helper*)malloc(sizeof(t_helper));
	piece->smesh_x = 0;
	piece->smesh_y = 0;
	alg->min_sum = -3;
	printf("Start alg\n");
	while (rules_check_y(meps, piece))// proverka na to shto est -1 or 0
	{
		while (rules_check_x(meps, piece))
		{
			if (rules_check(meps, piece, info))
				alg_get_info(meps, piece, alg, info);
			piece->smesh_x++;
		}
		piece->smesh_x = 0;
		piece->smesh_y++;
	}
	draw_result(alg, meps, piece, info);
}
