/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:15:27 by alvutina          #+#    #+#             */
/*   Updated: 2024/06/12 10:57:36 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack_elem *a, t_stack_elem *b, char **split_list, \
int to_free)
{
	int	i;

	if (to_free)
	{
		i = 0;
		while (split_list[i] != 0)
		{
			free(split_list[i]);
			i++;
		}
		free(split_list[i]);
		free(split_list);
	}
	if (a != NULL)
		free(a);
	if (b != NULL)
		free(b);
}

char	**split_args(int *argc, char **argv, int *to_free)
{
	char	**split_args;

	split_args = ft_split_mult(argv[0], " \t\n");
	*argc = args_len(split_args) + 1;
	*to_free = 1;
	return (split_args);
}

void	choose_sorting(t_stack_elem *a, t_stack_elem *b, int argc)
{
	if (argc == 3)
	{
		if (check_sorted(a, argc) == -1)
			ft_for_swap(a, "sa\n");
	}
	else if (argc == 4)
		sort_for_three(a);
	else
		global_sorting(a, b, argc);
}

int	check_sorted(t_stack_elem *stack, int argc)
{
	int	i;

	i = 0;
	if (argc > 1)
	{
		while (stack[i + 1].index != -1)
		{
			if (stack[i].value > stack[i + 1].value)
				return (-1);
			i++;
		}
	}
	return (1);
}

t_stack_elem	*initialize_stack(int argc, char **argv, int boolean)
{
	t_stack_elem	*tab;
	int				i;

	tab = malloc(sizeof(t_stack_elem) * (argc + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		if (boolean == 1)
		{
			tab[i].value = ft_atoi(argv[i]);
			tab[i].is_sorted = 1;
		}
		else
		{
			tab[i].value = 0;
			tab[i].is_sorted = 0;
		}
		tab[i].index = i;
		i++;
	}
	tab[i].index = -1;
	return (tab);
}
