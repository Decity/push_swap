/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:43:47 by elie              #+#    #+#             */
/*   Updated: 2024/07/05 09:19:01 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/include/libft.h"

typedef struct s_stack
{
	int				size;
	int				index_bot;
	int				*values;
}			t_stack;

typedef struct s_data
{
	t_stack			*stack_a;
	t_stack			*stack_b;

	int				argc;
	char			**values_as_str;
	unsigned int	total_size;
}	t_data;

// stack data
void	init_stacks(t_data *data);
void	set_stack_values(t_data *data);
int		malloc_stacks(t_data *data);

// free
void	free_stack(t_stack *stack);
void	free_stack_and_vals(t_stack *stack);
void	free_stacks_and_vals(t_data *data);
void	free_vals(t_data *data);

// validation
bool	is_sorted(t_stack *stack);
bool	is_valid_int(const char *str);
bool	has_valid_values(t_data *data);
bool	has_no_duplicates(t_stack *stack);

// Sort
void	sort(t_data *data);
void	sort_three(t_data *data);
void	sort_four(t_data *data);
void	sort_five(t_data *data);
void	sort_radix(t_data *data);

// operations
void	push(t_stack *src, t_stack *dst);
void	push_a(t_data *data);
void	push_b(t_data *data);

void	swap(t_stack *stack);
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	swap_s(t_data *data);

void	rotate(t_stack *stack);
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	rotate_r(t_data *data);

void	reverse_rotate(t_stack *stack);
void	reverse_rotate_a(t_data *data);
void	reverse_rotate_b(t_data *data);
void	reverse_rotate_r(t_data *data);

// UTILS
int		get_highest_value(t_stack *stack);
int		get_lowest_value(t_stack *stack);
int		get_second_lowest_value(t_stack *stack);
int		get_bits(t_stack *stack);
bool	is_overflow(const char *str);

// errors
void	push_swap_error(void);

#endif
