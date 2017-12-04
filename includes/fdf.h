/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 00:06:40 by eLopez            #+#    #+#             */
/*   Updated: 2017/12/04 13:34:00 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <ft_printf.h>
# include <get_next_line.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# define MAX(a, b) (a > b ? a : b)
# define MIN(a, b) (a < b ? a : b)
# define PI 3.14159265
# define KEY1 83
# define KEY2 84
# define KEY3 85
# define KEY4 86
# define KEY5 87
# define KEY6 88
# define KEY7 89
# define KEY8 91
# define KEY9 92
# define KEYMIN 78
# define KEYPLUS 69
# define KEYUP 126
# define KEYDOWN 125
# define KEYESC 53
# define KEYR 15
# define KEYG 5
# define KEYB 11

typedef struct	s_fdfcalc
{
	float	a;
	float	b;
	float	c;
}				t_fdfcalc;

typedef struct	s_pix
{
	int	x;
	int	y;
	int	z;
	int	x1;
	int	y1;
	int	z1;
	int	clr;
}				t_pix;

typedef struct	s_fdf
{
	void	*mlx;
	void	*img;
	void	*win;
	int		win_x;
	int		win_y;
	t_pix	**map;
	int		map_x;
	int		map_y;
	int		rot_x;
	int		rot_y;
	int		rot_z;
	int		speed;
	int		zoom;
	int		height;
	int		color;
}				t_fdf;

/*
**		These functions intialize variables in data structure t_fdf
*/
void			init_fdf(t_fdf *f);
void			re_init_fdf(t_fdf *f);

/*
**		This function deals with Parsing and Validating the given map
*/
void			fdf_input(t_fdf *f, char *file);

/*
**		This function Sets up the graphics Window
*/
void			fdf_window(t_fdf *f);

/*
**		This function Calculates: 3D coordinates in Matrix, and rotation
*/
void			fdf_matrix(t_fdf *f);

/*
**		These functions draw lines in the image, pixel for pixel
*/
void			fdf_image(t_fdf *f);
void			putpixel(t_fdf *f, t_pix a, int clr);

/*
**		This function displays instructions and default color value
*/
void			fdf_display(t_fdf *f);

/*
**		These functions deal with Exits due to errors or 'ESC'
*/
void			fdf_exit(t_fdf *f);
void			fdf_error(int error);

#endif
