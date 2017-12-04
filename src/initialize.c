/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:14:01 by eLopez            #+#    #+#             */
/*   Updated: 2017/11/21 22:56:09 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		re_init_fdf(t_fdf *f)
{
	f->rot_x = 45;
	f->rot_y = 20;
	f->rot_z = 0;
	f->speed = 5;
	if (f->map_x > 50)
		f->zoom = 5;
	else
		f->zoom = 20;
	f->height = 3;
	f->color = 0x0000ffff;
}

void		init_fdf(t_fdf *f)
{
	f->mlx = mlx_init();
	f->map_x = 0;
	f->map_y = 0;
	f->win_x = 0;
	f->win_y = 0;
	f->rot_x = 45;
	f->rot_y = 20;
	f->rot_z = 0;
	f->speed = 5;
	f->zoom = 5;
	f->height = 3;
	f->color = 0x0000ffff;
}
