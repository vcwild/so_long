/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:09:18 by vwildner          #+#    #+#             */
/*   Updated: 2022/01/20 21:19:35 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	read_map_nrows(char *argv_1)
{
	int		fd;
	int		counter;
	int		gnl;
	char	*line;

	counter = 0;
	gnl = 1;
	fd = open(argv_1, O_RDONLY);
	if (fd < 0)
		return (GNL_FOUND_EOF);
	while (gnl)
	{
		gnl = get_next_line(fd, &line);
		if (gnl < 0)
		{
			return (SO_LONG_FAIL);
		}
		counter++;
		free(line);
	}
	close(fd);
	return (counter);
}

static int	parse_map_for(int nrows, char *argv_1, t_program *program)
{
	int		fd;
	int		i;
	int		gnl;

	i = 0;
	gnl = 1;
	program->grid = (char **)ft_calloc(sizeof(char *), nrows + 1);
	if (!program->grid)
		return (SO_LONG_FAIL);
	fd = open(argv_1, O_RDONLY);
	while (gnl)
	{
		gnl = get_next_line(fd, &program->grid[i]);
		if (gnl < 0)
		{
			free_grid(program);
			return (SO_LONG_FAIL);
		}
		i++;
	}
	ensure_no_gnl_leaks(program, &nrows);
	close(fd);
	program->nrows = nrows;
	program->ncolumns = ft_strlen(program->grid[0]);
	return (SO_LONG_SUCCESS);
}

static int	verify_walls_for(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->ncolumns)
	{
		if (program->grid[0][i] != WALL
			|| program->grid[program->nrows - 1][i] != WALL)
			return (SO_LONG_FAIL);
		i++;
	}
	i = 0;
	while (i < program->nrows - 1)
	{
		if (program->grid[i][0] != WALL
			|| program->grid[i][program->ncolumns - 1] != WALL
			|| ft_strlen(program->grid[i]) != ft_strlen(program->grid[i + 1]))
			return (SO_LONG_FAIL);
		i++;
	}
	return (SO_LONG_SUCCESS);
}

static int	verify_valid_entities_for(t_program *program)
{
	int	row;
	int	col;

	row = 1;
	while (row <= program->nrows - 2)
	{
		col = 1;
		while (col <= program->ncolumns - 2)
		{
			if (program->grid[row][col] != COLLECTIBLE
				&& program->grid[row][col] != PLAYER_POSITION
				&& program->grid[row][col] != MAP_EXIT
				&& program->grid[row][col] != EMPTY_SPACE
				&& program->grid[row][col] != WALL)
			{
				free_grid(program);
				return (print_so_long_error(ERR_INVALID_MAP));
			}
			col++;
		}
		row++;
	}
	return (SO_LONG_SUCCESS);
}

int	verify_valid_game_for(char *argv_1, t_program *program)
{
	int	nrows;

	nrows = read_map_nrows(argv_1);
	if (!nrows)
		return (print_so_long_error(ERR_READ_MAP));
	if (!parse_map_for(nrows, argv_1, program))
	{
		free_grid(program);
		return (print_so_long_error(ERR_READ_MAP));
	}
	if (!verify_walls_for(program))
	{
		free_grid(program);
		return (print_so_long_error(ERR_INVALID_MAP));
	}
	if (!verify_valid_entities_for(program))
	{
		free_grid(program);
		return (print_so_long_error(ERR_INVALID_ENTITIES));
	}
	return (SO_LONG_SUCCESS);
}
