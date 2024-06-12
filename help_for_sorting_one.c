/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_for_sorting_one.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:14:41 by alvutina          #+#    #+#             */
/*   Updated: 2024/06/12 10:26:45 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_median_candidate(t_stack_elem *stack)
{
	int	start;
	int	end;

	start = search_first_elem_stack(stack);
	end = search_last_elem_stack(stack);
	while (start <= end)
	{
		if (find_median(stack, stack[start].value))
			return (stack[start].value);
		start++;
	}
	return (-1);
}

void	sort_for_three(t_stack_elem *stack)
{
	int	start;
	int	end;

	start = search_first_elem_stack(stack);
	end = search_last_elem_stack(stack);
	if (get_min_elem_stack(stack).index == start && \
	get_max_elem_stack(stack, -1).index == end)
		return ;
	if (get_min_elem_stack(stack).index == start && \
	get_max_elem_stack(stack, -1).index == end - 1)
	{
		ft_for_swap(stack, "sa\n");
		ft_for_rotate(stack, "ra\n");
	}
	if (get_max_elem_stack(stack, -1).index == start)
		ft_for_rotate(stack, "ra\n");
	if (stack[start].value > stack[start + 1].value)
		ft_for_swap(stack, "sa\n");
	if (get_min_elem_stack(stack).index == end)
		ft_for_reverse_rotate(stack, "rra\n");
}

void	handle_element_placement(t_stack_elem *a, t_stack_elem *b, \
int i, int stack_size)
{
	int	start;
	int	same;

	start = search_first_elem_stack(a);
	same = calculate_alignment(a, b, i);
	resolve_calculate_alignment(a, b, i);
	if (same != 0)
		i -= same;
	if (i >= stack_size - 2)
		i = start + (i - (stack_size - 1));
	else if (i < start)
		i = search_last_elem_stack(a) + i;
	i -= move_to_top(a, i, "rb\n", "rrb\n");
	if (i >= stack_size - 2)
		i = start + (i - (stack_size - 1));
	if (get_min_elem_stack(b).value > a[i].value \
	|| get_max_elem_stack(b, -1).value < a[i].value)
		move_to_top(b, get_min_elem_stack(b).index, "ra\n", "rra\n");
	else
		move_to_top(b, find_min_above_limit(b, a[i].value).index, \
		"ra\n", "rra\n");
	ft_for_push(a, b, "pa\n");
}

int	calculate_operations_for_placement(t_stack_elem *a, \
int index, int reel)
{
	int	count_op;
	int	start;
	int	end;
	int	median;

	count_op = 0;
	start = search_first_elem_stack(a);
	end = search_last_elem_stack(a);
	median = start + ((end - start) / 2);
	if (index > median)
	{
		count_op = end - index + 1;
		if (reel == 1)
			count_op = -count_op;
	}
	else if (index <= median)
		count_op = index - start;
	return (count_op);
}

int	calculate_operations_for_good_placement(t_stack_elem *a, \
t_stack_elem *b, int index)
{
	int				count_op;
	int				coherence;
	t_stack_elem	min_num_behind;

	count_op = 0;
	count_op += calculate_operations_for_placement(a, index, 0);
	if (get_min_elem_stack(b).value > a[index].value \
	|| get_max_elem_stack(b, -1).value < a[index].value)
		count_op += calculate_operations_for_placement(b, \
		get_min_elem_stack(b).index, 0);
	else
	{
		min_num_behind = find_min_above_limit(b, a[index].value);
		count_op += calculate_operations_for_placement(b, \
		b[min_num_behind.index].index, 0);
	}
	coherence = calculate_alignment(a, b, index);
	if (coherence < 0)
		coherence = -coherence;
	count_op = count_op - coherence;
	return (count_op + 1);
}
