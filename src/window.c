/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:50:53 by eLopez            #+#    #+#             */
/*   Updated: 2017/11/21 23:23:35 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	fdf_window(t_fdf *f)
{
	f->win_x = (f->map_x * f->zoom) * 4;
	f->win_y = (f->map_y * f->zoom) * 4;
	if (f->win_x < 1200)
		f->win_x = 1200;
	else if (f->win_x > 1900)
		f->win_x = 1900;
	if (f->win_y < 400)
		f->win_y = 400;
	else if (f->win_y > 1000)
		f->win_y = 1000;
	f->win = mlx_new_window(f->mlx, f->win_x, f->win_y, "fdf 42");
}
