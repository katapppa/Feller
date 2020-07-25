/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:00:00 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/25 18:13:55 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "../libft/libft.h"
#include "../libft/get_next_line.h"

typedef		struct	s_filler
{
	int		coord_x;
	int		coord_y;
	char	**map;
}					t_filler;

typedef		struct	s_feller
{
	int		player;
}					t_feller;

void        get_map(t_filler *meps);

#endif