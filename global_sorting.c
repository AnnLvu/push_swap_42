/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:14:27 by alvutina          #+#    #+#             */
/*   Updated: 2024/06/12 10:26:40 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	global_sorting(t_stack_elem *a, t_stack_elem *b, int stack_size)
{
	int	index;
	int	median;

	index = search_first_elem_stack(a);
	median = is_median_candidate(a);
	while (index < stack_size - 4)
	{
		ft_for_push(a, b, "pb\n");
		if (b[search_first_elem_stack(b)].value > median && \
		search_last_elem_stack(a) - search_first_elem_stack(a) + 1 > 3)
			ft_for_rotate(b, "rb\n");
		index++;
	}
	sort_for_three(a);
	index = search_first_elem_stack(b);
	while (index < search_last_elem_stack(b))
	{
		handle_element_placement(b, a, \
		find_min_cost_index(b, a, stack_size), stack_size);
		index++;
	}
	move_to_top(a, find_min_above_limit(a, b[index].value).index, \
	"ra\n", "rra\n");
	ft_for_push(b, a, "pa\n");
	move_to_top(a, get_min_elem_stack(a).index, "ra\n", "rra\n");
}
