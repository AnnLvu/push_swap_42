/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:15:29 by alvutina          #+#    #+#             */
/*   Updated: 2024/06/12 10:27:15 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_first_elem_stack(t_stack_elem *name_stack)
{
	int	first;

	first = 0;
	while (name_stack[first].is_sorted != 1)
		first++;
	if (name_stack[first].index == -1)
		first--;
	return (first);
}

int	search_last_elem_stack(t_stack_elem *name_stack)
{
	int	end;

	end = 0;
	while (name_stack[end].index != -1)
		end++;
	end--;
	return (end);
}

t_stack_elem	get_max_elem_stack(t_stack_elem *stack, int param)
{
	int	start;
	int	end;
	int	max;

	start = search_first_elem_stack(stack);
	end = search_last_elem_stack(stack);
	max = -1;
	while (start <= end)
	{
		if (max == -1 || ((stack[start].value > stack[max].value || \
		stack[max].is_sorted == -1) && (param == -1 || \
		stack[start].value < param)))
			max = stack[start].index;
		start++;
	}
	return (stack[max]);
}

t_stack_elem	get_min_elem_stack(t_stack_elem *stack)
{
	int	start;
	int	end;
	int	min;

	start = search_first_elem_stack(stack);
	end = search_last_elem_stack(stack);
	min = stack[start].index;
	while (start <= end)
	{
		if (stack[start].value < stack[min].value)
			min = stack[start].index;
		start++;
	}
	return (stack[min]);
}

t_stack_elem	find_min_above_limit(t_stack_elem *stack, int limit)
{
	int	start;
	int	end;
	int	min;

	start = search_first_elem_stack(stack);
	end = search_last_elem_stack(stack);
	min = -1;
	while (start <= end)
	{
		if (stack[start].value > limit && \
		(min == -1 || stack[start].value < stack[min].value))
			min = stack[start].index;
		start++;
	}
	if (min == -1)
		return (get_min_elem_stack(stack));
	return (stack[min]);
}
