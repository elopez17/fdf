/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:45:33 by eLopez            #+#    #+#             */
/*   Updated: 2017/11/21 17:05:29 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	putpixel(t_fdf *f, t_pix a, int clr)
{
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
	int		i;

	i = 0;
	if (a.x >= f->win_x || a.y >= f->win_y || a.x < 0 || a.y < 0)
		return ;
	addr = mlx_get_data_addr(f->img, &bpp, &len, &endian);
	if (endian == 0)
		while (i != bpp / 8)
		{
			addr[a.y * len + a.x * (bpp / 8) + i++] = (0x000000ff & clr);
			addr[a.y * len + a.x * (bpp / 8) + i++] = (0x0000ff00 & clr) >> 8;
			addr[a.y * len + a.x * (bpp / 8) + i++] = (0x00ff0000 & clr) >> 16;
			addr[a.y * len + a.x * (bpp / 8) + i++] = (0xff000000 & clr) >> 24;
		}
}
