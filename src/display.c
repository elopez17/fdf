/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:51:57 by eLopez            #+#    #+#             */
/*   Updated: 2017/11/22 12:09:07 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	fdf_display2(t_fdf *f)
{
	mlx_string_put(f->mlx, f->win, f->win_x - 380, 60, 0x00ffff00, \
			"Press 2 or 8 to rotate around Y Axis");
	mlx_string_put(f->mlx, f->win, f->win_x - 380, 35, 0x0000ffff, \
			"Press 4 or 6 to rotate around X Axis");
	mlx_string_put(f->mlx, f->win, f->win_x - 330, f->win_y - 75, 0x00ff0000, \
			"Press 5 to RESET adjusted values");
	mlx_string_put(f->mlx, f->win, f->win_x - 390, f->win_y - 50, 0x00ff0000, \
			"Press 7 to Decrease Height of z values");
	mlx_string_put(f->mlx, f->win, f->win_x - 400, f->win_y - 25, 0x0000ff00, \
			"Press 9 to Inccrease Height of z values");
	mlx_string_put(f->mlx, f->win, 10, f->win_y - 50, 0x00ff0000, \
			"Press '-' to Decrease Speed of adjustments");
	mlx_string_put(f->mlx, f->win, 10, f->win_y - 25, 0x0000ff00, \
			"Press '+' to Increase Speed of adjustments");
}

void		fdf_display(t_fdf *f)
{
	mlx_string_put(f->mlx, f->win, 10, 10, 0x00ffffff, \
			"Current Default Color: ");
	mlx_string_put(f->mlx, f->win, 250, 10, 0x00ff0000, \
			(f->color & 0x00ff0000 ? "R" : " "));
	mlx_string_put(f->mlx, f->win, 265, 10, 0x0000ff00, \
			(f->color & 0x0000ff00 ? "G" : " "));
	mlx_string_put(f->mlx, f->win, 280, 10, 0x0000ffff, \
			(f->color & 0x000000ff ? "B" : " "));
	mlx_string_put(f->mlx, f->win, 10, 35, 0x0000ff00, \
			"Press UP Arrow to ZOOM IN");
	mlx_string_put(f->mlx, f->win, 10, 60, 0x00ff0000, \
			"Press DOWN Arrow to ZOOM OUT");
	mlx_string_put(f->mlx, f->win, f->win_x - 330, 10, 0x00ffffff, \
			"Using the Number Pad:");
	mlx_string_put(f->mlx, f->win, f->win_x - 330, 13, 0x00ffffff, \
			"_____________________");
	mlx_string_put(f->mlx, f->win, f->win_x - 380, 85, 0x0000ff00, \
			"Press 1 or 3 to rotate around Z Axis");
	fdf_display2(f);
}
