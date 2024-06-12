/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_for_sorting_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:14:51 by alvutina          #+#    #+#             */
/*   Updated: 2024/06/12 10:26:50 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(t_stack_elem *stack, int value)
{
	int	start;
	int	end;
	int	big;
	int	small;

	start = search_first_elem_stack(stack);
	end = search_last_elem_stack(stack);
	big = 0;
	small = 0;
	while (start <= end)
	{
		if (stack[start].value > value)
			big++;
		else if (stack[start].value < value)
			small++;
		start++;
	}
	if ((big - small) >= -1 && (big - small) <= 1)
		return (1);
	return (0);
}

int	move_to_top(t_stack_elem *a, int index, char *r, char *rr)
{
	int	num_operations;
	int	remaining_operations;
	int	sign;

	remaining_operations = calculate_operations_for_placement(a, index, 1);
	sign = remaining_operations;
	if (remaining_operations < 0)
		remaining_operations = -remaining_operations;
	num_operations = remaining_operations;
	if (remaining_operations != 0)
	{
		while (remaining_operations > 0)
		{
			if (sign > 0)
				ft_for_rotate(a, r);
			else
				ft_for_reverse_rotate(a, rr);
			remaining_operations--;
		}
	}
	if (sign > 0)
		sign = 1;
	else
		sign = -1;
	return (sign * num_operations);
}

int	calculate_alignment(t_stack_elem *a, t_stack_elem *b, int index)
{
	int	operations_a;
	int	operations_b;
	int	distance;
	int	min_index;

	operations_a = calculate_operations_for_placement(a, index, 1);
	if (get_min_elem_stack(b).value > a[index].value || \
		get_max_elem_stack(b, -1).value < a[index].value)
	{
		operations_b = calculate_operations_for_placement(b, \
		get_min_elem_stack(b).index, 1);
	}
	else
	{
		min_index = find_min_above_limit(b, a[index].value).index;
		operations_b = calculate_operations_for_placement(b, min_index, 1);
	}
	distance = 0;
	if (operations_a > 0 && operations_b > 0)
		distance = ft_min(operations_a, operations_b);
	if (operations_a < 0 && operations_b < 0)
		distance = ft_max(operations_a, operations_b);
	return (distance);
}

void	resolve_calculate_alignment(t_stack_elem *a, t_stack_elem *b, int index)
{
	int	dist;

	dist = calculate_alignment(a, b, index);
	if (dist > 0)
	{
		while (dist > 0)
		{
			rr_rrr(a, b, 0);
			dist--;
		}
	}
	else if (dist < 0)
	{
		dist = -dist;
		while (dist > 0)
		{
			rr_rrr(a, b, 1);
			dist--;
		}
	}
}

int	find_min_cost_index(t_stack_elem *a, t_stack_elem *b, int stack_size)
{
	int				i;
	int				cost;
	int				start;
	t_stack_elem	min_cost_element;

	start = search_first_elem_stack(a);
	i = start;
	min_cost_element.value = -1;
	while (i < stack_size - 1)
	{
		cost = calculate_operations_for_good_placement(a, b, i);
		if (cost < min_cost_element.value || min_cost_element.value == -1)
		{
			min_cost_element.value = cost;
			min_cost_element.index = i;
		}
		i++;
	}
	return (min_cost_element.index);
}
