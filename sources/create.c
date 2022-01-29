/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:54:01 by vwildner          #+#    #+#             */
/*   Updated: 2022/01/20 18:54:17 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_program	*get_program(void)
{
	static t_program	program;

	return (&program);
}

t_point	*create_point(int x, int y)
{
	t_point	*point;

	point = (t_point *)ft_calloc(sizeof(t_point), 1);
	point->x = x;
	point->y = y;
	return (point);
}
