/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:17:45 by eLopez            #+#    #+#             */
/*   Updated: 2017/11/15 01:16:44 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	fdf_error(int error)
{
	char	*msg[] =
	{
		"invalid amount of arguements",
		"invalid map",
		"failed to open file",
		"lines are not equal"
	};
	ft_printf("fdf: %{RD}%s%{NC}\nusage: ./fdf <map>\n", msg[error]);
	exit(0);
}
