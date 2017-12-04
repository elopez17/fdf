/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:40:22 by eLopez            #+#    #+#             */
/*   Updated: 2017/11/21 22:29:18 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	straight(t_fdf *f, t_pix a, t_pix b)
{
	int	route;

	if (a.x == b.x)
	{
		route = a.y > b.y ? -1 : 1;
		while (a.y != b.y)
		{
			putpixel(f, a, (a.clr == 0 ? f->color : a.clr));
			a.y += route;
		}
	}
	else
	{
		route = a.x > b.x ? -1 : 1;
		while (a.x != b.x)
		{
			putpixel(f, a, (a.clr == 0 ? f->color : a.clr));
			a.x += route;
		}
	}
}

static void	diagonal_x(t_fdf *f, t_pix a, t_pix b)
{
	float	slope;
	float	trunc;

	slope = (float)(b.y - a.y) / (float)(b.x - a.x);
	trunc = a.y;
	while (a.x != b.x)
	{
		a.y = trunc;
		trunc += slope;
		++a.x;
		putpixel(f, a, (a.clr == 0 ? f->color : a.clr));
	}
}

static void	diagonal_y(t_fdf *f, t_pix a, t_pix b)
{
	float	slope;
	float	trunc;

	slope = (float)(b.x - a.x) / (float)(b.y - a.y);
	trunc = a.x;
	while (a.y != b.y)
	{
		a.x = trunc;
		trunc += slope;
		++a.y;
		putpixel(f, a, (a.clr == 0 ? f->color : a.clr));
	}
}

static void	drawline(t_fdf *f, t_pix *a, t_pix *b)
{
	if (a->x == b->x || a->y == b->y)
		straight(f, *a, *b);
	else if (abs(a->x - b->x) >= abs(a->y - b->y))
		if (a->x < b->x)
			diagonal_x(f, *a, *b);
		else
			diagonal_x(f, *b, *a);
	else
		if (a->y < b->y)
			diagonal_y(f, *a, *b);
		else
			diagonal_y(f, *b, *a);
}

void		fdf_image(t_fdf *f)
{
	int		x;
	int		y;

	f->img = mlx_new_image(f->mlx, f->win_x, f->win_y);
	y = -1;
	while (++y < f->map_y)
	{
		x = -1;
		while (++x < f->map_x)
		{
			if (x < f->map_x - 1)
				drawline(f, &f->map[y][x], &f->map[y][x + 1]);
			if (y < f->map_y - 1)
				drawline(f, &f->map[y][x], &f->map[y + 1][x]);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_destroy_image(f->mlx, f->img);
	fdf_display(f);
}
