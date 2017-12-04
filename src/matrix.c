/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:20:48 by eLopez            #+#    #+#             */
/*   Updated: 2017/11/30 11:42:23 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	rotate(t_fdf *f, t_pix *pix)
{
	float	angle;
	float	tmp[2];

	angle = (PI * f->rot_x) / 180;
	tmp[0] = pix->z * cos(angle) + pix->y1 * sin(angle);
	tmp[1] = pix->y1 * cos(angle) - pix->z * sin(angle);
	pix->z = round(tmp[0]);
	pix->y1 = round(tmp[1]);
	angle = (PI * f->rot_y) / 180;
	tmp[0] = pix->x1 * cos(angle) + pix->z * sin(angle);
	tmp[1] = pix->z * cos(angle) - pix->x1 * sin(angle);
	pix->x1 = round(tmp[0]);
	pix->z = round(tmp[1]);
	angle = (PI * f->rot_z) / 180;
	tmp[0] = pix->x1 * cos(angle) + pix->y1 * sin(angle);
	tmp[1] = pix->y1 * cos(angle) - pix->x1 * sin(angle);
	pix->x1 = round(tmp[0]);
	pix->y1 = round(tmp[1]);
}

void		fdf_matrix(t_fdf *f)
{
	t_fdfcalc	floats;
	int			x;
	int			y;

	f->zoom == 5 && f->map_x <= 50 ? f->zoom += 15 : 0;
	y = -1;
	while (++y < f->map_y)
	{
		x = -1;
		while (++x < f->map_x)
		{
			f->map[y][x].x1 = (x - (f->map_x/2)) * f->zoom;
			f->map[y][x].y1 = (y - (f->map_y/2)) * f->zoom;
			f->map[y][x].z = f->map[y][x].z1 * f->height;
			rotate(f, &f->map[y][x]);
			floats.a = f->map[y][x].x1;
			floats.b = f->map[y][x].y1;
			floats.c = f->map[y][x].z - 1000;
			f->map[y][x].x = (floats.a / floats.c) * -750;
			f->map[y][x].x += (f->win_x / 2);
			f->map[y][x].y = (floats.b / floats.c) * -750;
			f->map[y][x].y += (f->win_y / 2);
		}
	}
	fdf_image(f);
}
