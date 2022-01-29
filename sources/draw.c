/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:54:33 by vwildner          #+#    #+#             */
/*   Updated: 2022/01/29 09:07:06 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_image_in_map(t_program *program, void *image, int col, int row)
{
	mlx_put_image_to_window(
		program->mlx_ptr,
		program->win_ptr,
		image,
		col * SPRITE_SIZE,
		row * SPRITE_SIZE);
	return (MLX_SUCCESS);
}

int	draw_map(t_program *program)
{
	t_dispatcher	**dispatch;
	int				row;
	int				col;
	int				element;

	load_sprites(program);
	dispatch = get_dispatcher();
	row = -1;
	while (program->grid[++row])
	{
		col = -1;
		while (program->grid[row][++col])
		{
			element = (int)program->grid[row][col];
			dispatch[element](program, row, col);
		}
	}
	draw_steps(program);
	destroy_sprites(program);
	return (MLX_SUCCESS);
}

int	draw_steps(t_program *program)
{
	char	*count;
	char	*steps;
	int		n_pixel_cols;

	steps = ft_calloc(sizeof(char), 100);
	count = ft_itoa(program->player.steps);
	n_pixel_cols = (program->ncolumns * SPRITE_SIZE);
	ft_strcopy(steps, "Steps: ", 7);
	ft_strcopy(&steps[ft_strlen(steps)], count, ft_strlen(count) + 1);
	printf("%s\n", steps);
	mlx_string_put(
		program->mlx_ptr, program->win_ptr,
		n_pixel_cols / 2 - 30, 16, COLOR_WHITE, steps);
	free(steps);
	free(count);
	return (MLX_SUCCESS);
}
