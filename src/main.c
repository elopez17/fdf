/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:16:41 by eLopez            #+#    #+#             */
/*   Updated: 2017/11/22 13:47:33 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	keypressed(int key, t_fdf *f)
{
	key == KEY1 ? f->rot_z -= f->speed : 0;
	key == KEY2 ? f->rot_y -= f->speed : 0;
	key == KEY3 ? f->rot_z += f->speed : 0;
	key == KEY4 ? f->rot_x -= f->speed : 0;
	key == KEY5 ? re_init_fdf(f) : 0;
	key == KEY6 ? f->rot_x += f->speed : 0;
	key == KEY7 ? --f->height : 0;
	key == KEY8 ? f->rot_y += f->speed : 0;
	key == KEY9 ? ++f->height : 0;
	key == KEYMIN ? --f->speed : 0;
	key == KEYPLUS ? ++f->speed : 0;
	key == KEYUP && f->zoom * MAX(f->map_x, f->map_y) <= \
		 						MIN(f->win_x, f->win_y) ? f->zoom += 2 : 0;
	key == KEYDOWN && f->zoom > 2 ? f->zoom -= 2 : 0;
	key == KEYESC ? fdf_exit(f) : 0;
	key == KEYR ? f->color ^= 0x00ff0000 : 0;
	key == KEYG ? f->color ^= 0x0000ff00 : 0;
	key == KEYB ? f->color ^= 0x000000ff : 0;
	fdf_matrix(f);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	f;

	if (argc != 2)
		fdf_error(0);
	init_fdf(&f);
	fdf_input(&f, argv[1]);
	fdf_window(&f);
	fdf_matrix(&f);
	mlx_hook(f.win, 2, 0, &keypressed, &f);
	mlx_loop(f.mlx);
	return (0);
}
