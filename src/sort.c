/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:47:55 by elie              #+#    #+#             */
/*   Updated: 2024/03/28 15:27:53 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_data *data);
void	sort_three(t_data *data);
void	sort_four(t_data *data);
void	sort_five(t_data *data);
void	sort_radix(t_data *data);

void	sort(t_data *data)
{
	if (is_sorted(data->stack_a) == true)
		return ;
	if (data->total_size == 2)
		rotate_a(data);
	else if (data->total_size == 3)
		sort_three(data);
	else if (data->total_size == 4)
		sort_four(data);
	else if (data->total_size == 5)
		sort_five(data);
	else
		sort_radix(data);
}

void	sort_three(t_data *data)
{
	int	*stack;

	stack = data->stack_a->values;
	if ((stack[0] > stack[1] && stack[2] > stack[0])
		|| (stack[0] > stack[1] && stack[1] > stack[2])
		|| (stack[2] > stack[0] && stack[1] > stack[2])
	)
		swap_a(data);
	if ((stack[0] > stack[2] && stack[2] > stack[1]))
		rotate_a(data);
	if ((stack[1] > stack[0] && stack[0] > stack[2]))
		reverse_rotate_a(data);
}

void	sort_four(t_data *data)
{
	int	lowest_value;

	lowest_value = get_lowest_value(data->stack_a);
	while (data->stack_a->size > 3)
	{
		if (data->stack_a->values[0] == lowest_value)
			push_b(data);
		else
			rotate_a(data);
	}
	if (is_sorted(data->stack_a) == false)
		sort_three(data);
	push_a(data);
}

void	sort_five(t_data *data)
{
	int	lowest_value;
	int	second_value;

	lowest_value = get_lowest_value(data->stack_a);
	second_value = get_second_lowest_value(data->stack_a);
	while (data->stack_a->size > 3)
	{
		if (data->stack_a->values[0] == lowest_value
			|| data->stack_a->values[0] == second_value
		)
			push_b(data);
		else
			rotate_a(data);
	}
	if (is_sorted(data->stack_a) == false)
		sort_three(data);
	if (data->stack_b->values[0] < data->stack_b->values[1])
		swap_b(data);
	push_a(data);
	push_a(data);
}

void	sort_radix(t_data *data)
{
	int	max_bits;
	int	max_index;
	int	i;
	int	j;

	max_bits = get_bits(data->stack_a);
	max_index = data->stack_a->index_bot;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j <= max_index)
		{
			if ((data->stack_a->values[0] >> i) & 1)
				rotate_a(data);
			else
				push_b(data);
			j++;
		}
		while (data->stack_b->size != 0)
			push_a(data);
		i++;
	}
}
