/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:56:27 by eLopez            #+#    #+#             */
/*   Updated: 2017/11/21 16:42:50 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	pixcolor(int pxnbr, char *pixel)
{
	int		i;
	int		clr;

	clr = 0;
	i = ft_numlen(pxnbr);
	if (pixel[i] == ',')
		while (pixel[++i])
		{
			if (pixel[i] >= '0' && pixel[i] <= '9')
				clr = clr * 16 + (pixel[i] - '0');
			else if (pixel[i] >= 'a' && pixel[i] <= 'f')
				clr = clr * 16 + (pixel[i] - 87);
			else if (pixel[i] >= 'A' && pixel[i] <= 'F')
				clr = clr * 16 + (pixel[i] - 55);
		}
	else if (pixel[i] != '\0')
		fdf_error(1);
	return (clr);
}

static void	setmap_xy(t_fdf *f, char *file)
{
	int		fd;
	char	*line;
	int		j;

	if ((fd = open(file, O_RDONLY)) < 0)
		fdf_error(2);
	while (get_next_line(fd, &line) == 1)
	{
		++f->map_y;
		if (f->map_x == 0)
			f->map_x = ft_countwords(line, ' ');
		if (f->map_x != ft_countwords(line, ' '))
			fdf_error(3);
		ft_strdel(&line);
	}
	close(fd);
	if (f->map_y == 0)
		fdf_error(1);
	f->map = (t_pix**)ft_memalloc(sizeof(t_pix*) * (f->map_y + 1));
	j = -1;
	while (++j < f->map_y)
		f->map[j] = (t_pix*)ft_memalloc(sizeof(t_pix) * f->map_x + 1);
}

void		fdf_input(t_fdf *f, char *file)
{
	int		fd;
	char	*line;
	char	**split;
	int		i;
	int		j;

	setmap_xy(f, file);
	(fd = open(file, O_RDONLY)) < 0 ? fdf_error(2) : 0;
	j = -1;
	while (get_next_line(fd, &line) == 1)
	{
		split = ft_strsplit(line, ' ');
		++j;
		i = -1;
		while (split[++i])
		{
			f->map[j][i].z1 = ft_atoi(split[i]);
			f->map[j][i].clr = pixcolor(f->map[j][i].z1, split[i]);
		}
		free_2d(&split);
		ft_strdel(&line);
	}
	close(fd);
}
