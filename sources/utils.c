/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:15:33 by vwildner          #+#    #+#             */
/*   Updated: 2022/02/02 14:12:35 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_exit(int keycode, t_program *program)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(program->mlx_ptr, program->win_ptr);
		free(program->mlx_ptr);
		exit(0);
	}
	return (0);
}

int	handle_keyrelease(int keycode, t_program *program)
{
	printf("%d\n", keycode);
	printf("%p", program->win_ptr);
	return (0);
}

int	handle_no_event(t_program *program)
{
	printf("%p", program->win_ptr);
	return (0);
}

int	ensure_no_gnl_leaks(t_program *program, int *nrows)
{
	if (ft_strlen(program->grid[(*nrows) - 1]) == 0)
	{
		*nrows = (*nrows) - 1;
		free(program->grid[(*nrows)]);
	}
	program->grid[(*nrows)] = NULL;
	return (SO_LONG_SUCCESS);
}
