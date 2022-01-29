/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:51:46 by vcwild            #+#    #+#             */
/*   Updated: 2022/01/20 18:52:38 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_input_args(int argc, char *argv_1)
{
	char	*dot_ber_substr;

	if (argc == 2)
	{
		dot_ber_substr = ft_strnstr(
				(const char *)argv_1,
				".ber",
				ft_strlen(argv_1) + 1);
		if (!dot_ber_substr)
			return (print_so_long_error(ERR_INVALID_MAP));
		return (SO_LONG_SUCCESS);
	}
	return (print_so_long_error(ERR_INVALID_ARGUMENTS));
}
