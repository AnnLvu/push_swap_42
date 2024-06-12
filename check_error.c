/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:14:31 by alvutina          #+#    #+#             */
/*   Updated: 2024/06/12 10:26:35 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		if (argv[i][j] == '\0' || !ft_isdigit(argv[i][j]))
			return (-1);
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				if (!(j == 0 && argv[i][j] == '-'))
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 2)
	{
		if (ft_atoi(argv[0]) == 2147483650)
			return (-1);
	}
	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (ft_atoi(argv[i]) == 2147483650 \
				|| ft_atoi(argv[j]) == 2147483650)
				return (-1);
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_error(int argc, char **argv)
{
	if (argc < 2)
	{
		return (0);
	}
	if (is_number(argc, argv) == -1)
	{
		ft_putstr_fd(ERROR_MSG, 2);
		return (ERR_INVALID_INPUT);
	}
	if (is_duplicate(argc, argv) == -1)
	{
		ft_putstr_fd(ERROR_MSG, 2);
		return (ERR_DUPLICATE);
	}
	return (1);
}
