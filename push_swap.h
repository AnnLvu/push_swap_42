/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:15:14 by alvutina          #+#    #+#             */
/*   Updated: 2024/06/12 10:53:27 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define ERROR_MSG "Error\n"
# define ERR_INVALID_INPUT -1
# define ERR_DUPLICATE -2
# define ERR_NOT_SORTED -3

typedef struct s_stack_elem {
	int		value;
	int		is_sorted;
	int		index;
}	t_stack_elem;

void			ft_for_swap(t_stack_elem *name_stack, char *message);
void			ft_for_push(t_stack_elem *a, t_stack_elem *b, char *message);
void			ft_for_rotate(t_stack_elem *name_stack, char *message);
void			ft_for_reverse_rotate(t_stack_elem *name_stack, char *message);
void			rr_rrr(t_stack_elem *a, t_stack_elem *b, int direction);
void			global_sorting(t_stack_elem *a, t_stack_elem *b, \
int stack_size);
int				is_median_candidate(t_stack_elem *stack);
void			sort_for_three(t_stack_elem *stack);
void			handle_element_placement(t_stack_elem *a, t_stack_elem *b, \
int i, int stack_size);
int				calculate_operations_for_placement(t_stack_elem *a, \
int index, int reel);
int				calculate_operations_for_good_placement(t_stack_elem *a, \
t_stack_elem *b, int index);
int				find_median(t_stack_elem *stack, int value);
int				move_to_top(t_stack_elem *a, int index, char *r, char *rr);
int				calculate_alignment(t_stack_elem *a, t_stack_elem *b, \
int index);
void			resolve_calculate_alignment(t_stack_elem *a, t_stack_elem *b, \
int index);
int				find_min_cost_index(t_stack_elem *a, t_stack_elem *b, \
int stack_size);
void			ft_putstr_fd(char *s, int fd);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
int				args_len(char **split_args);
long int		ft_atoi(const char *str);
int				search_first_elem_stack(t_stack_elem *name_stack);
int				search_last_elem_stack(t_stack_elem *name_stack);
t_stack_elem	get_max_elem_stack(t_stack_elem *stack, int param);
t_stack_elem	get_min_elem_stack(t_stack_elem *stack);
t_stack_elem	find_min_above_limit(t_stack_elem *stack, int limit);
int				main(int argc, char **argv);
void			ft_free(t_stack_elem *a, t_stack_elem *b, \
char **split_list, int to_free);
char			**split_args(int *argc, char **argv, int *to_free);
void			choose_sorting(t_stack_elem *a, t_stack_elem *b, int argc);
int				check_sorted(t_stack_elem *stack, int argc);
t_stack_elem	*initialize_stack(int argc, char **argv, int boolean);
char			**ft_split_mult(char *str, char *charset);
int				check_error(int argc, char **argv);
int				is_duplicate(int argc, char **argv);
int				is_number(int argc, char **argv);
int				ft_isdigit(int c);

#endif
