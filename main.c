/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:15:02 by alvutina          #+#    #+#             */
/*   Updated: 2024/06/12 10:57:29 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int				error;
	t_stack_elem	*a;
	t_stack_elem	*b;
	char			**split_list;
	int				to_free;

	to_free = 0;
	argv++;
	split_list = argv;
	if (argc == 2)
		split_list = split_args(&argc, argv, &to_free);
	error = check_error(argc, split_list);
	if (error < 0)
	{
		ft_free(NULL, NULL, split_list, to_free);
		return (0);
	}
	a = initialize_stack(argc, split_list, 1);
	b = initialize_stack(argc, split_list, 0);
	if (check_sorted(a, argc) == -1)
		choose_sorting(a, b, argc);
	ft_free(a, b, split_list, to_free);
	return (0);
}
