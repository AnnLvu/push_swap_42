/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:15:18 by alvutina          #+#    #+#             */
/*   Updated: 2024/06/12 10:27:02 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_for_swap(t_stack_elem *name_stack, char *message)
{
	int	first;
	int	temp;

	first = search_first_elem_stack(name_stack);
	temp = name_stack[first].value;
	name_stack[first].value = name_stack[first +1].value;
	name_stack[first + 1].value = temp;
	ft_putstr_fd(message, 1);
}

void	ft_for_push(t_stack_elem *a, t_stack_elem *b, char *message)
{
	int	first;
	int	end;

	first = 0;
	while (a[first].is_sorted != 1)
		first++;
	end = 0;
	while (b[end].index != -1 && b[end].is_sorted != 1)
		end++;
	end--;
	b[end].value = a[first].value;
	a[first].value = 0;
	b[end].is_sorted = 1;
	a[first].is_sorted = 0;
	ft_putstr_fd(message, 1);
}

void	ft_for_rotate(t_stack_elem *stack, char *message)
{
	int	start;
	int	end;
	int	tempnum;
	int	tempnum2;
	int	i;

	start = 0;
	while (stack[start].index != -1 && stack[start].is_sorted != 1)
		start++;
	end = 0;
	while (stack[end].index != -1)
		end++;
	end--;
	i = end;
	tempnum = stack[i].value;
	while (i > start)
	{
		tempnum2 = stack[i - 1].value;
		stack[i - 1].value = tempnum;
		tempnum = tempnum2;
		i--;
	}
	stack[end].value = tempnum;
	ft_putstr_fd(message, 1);
}

void	ft_for_reverse_rotate(t_stack_elem *stack, char *message)
{
	int	start;
	int	end;
	int	tempnum;
	int	tempnum2;
	int	i;

	start = 0;
	while (stack[start].index != -1 && stack[start].is_sorted != 1)
		start++;
	end = 0;
	while (stack[end].index != -1)
		end++;
	end--;
	i = start;
	tempnum = stack[i].value;
	while (i < end)
	{
		tempnum2 = stack[i + 1].value;
		stack[i + 1].value = tempnum;
		tempnum = tempnum2;
		i++;
	}
	stack[start].value = tempnum;
	ft_putstr_fd(message, 1);
}

void	rr_rrr(t_stack_elem *a, t_stack_elem *b, int direction)
{
	if (direction == 1)
	{
		ft_for_reverse_rotate(a, NULL);
		ft_for_reverse_rotate(b, NULL);
		ft_putstr_fd("rrr\n", 1);
	}
	else
	{
		ft_for_rotate(a, NULL);
		ft_for_rotate(b, NULL);
		ft_putstr_fd("rr\n", 1);
	}
}
