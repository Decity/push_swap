/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:47:55 by elie              #+#    #+#             */
/*   Updated: 2024/07/04 15:18:18 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stacks(t_data *data);
void	set_stack_values(t_data *data);
int		malloc_stacks(t_data *data);
int		get_rank(int i, char **str_values);

void	init_stacks(t_data *data)
{
	if (has_valid_values(data) == false)
	{
		free_vals(data);
		push_swap_error();
	}
	if (malloc_stacks(data) == -1)
		push_swap_error();
	set_stack_values(data);
	if (has_no_duplicates(data->stack_a) == false)
	{
		free_stacks_and_vals(data);
		push_swap_error();
	}
}

int	get_rank(int i, char **str_values)
{
	int	j;
	int	rank;

	j = 0;
	rank = 0;
	while (str_values[j])
	{
		if (ft_atoi(str_values[i]) > ft_atoi(str_values[j]))
			rank++;
		j++;
	}
	return (rank);
}

void	set_stack_values(t_data *data)
{
	int		i;
	t_stack	*a;

	a = data->stack_a;
	i = 0;
	while (data->values_as_str[i])
		i++;
	a->size = i;
	a->index_bot = i - 1;
	i = 0;
	while (i < data->stack_a->size)
	{
		a->values[i] = get_rank(i, data->values_as_str);
		i++;
	}
	data->stack_b->size = 0;
	data->stack_b->index_bot = 0;
}

int	malloc_stacks(t_data *data)
{
	data->stack_a = malloc(sizeof(t_stack));
	if (!data->stack_a)
		return (-1);
	data->stack_b = malloc(sizeof(t_stack));
	if (!data->stack_b)
	{
		free_stack(data->stack_a);
		return (-1);
	}
	data->stack_a->values = malloc(data->total_size * sizeof(int));
	if (!data->stack_a->values)
	{
		free_stack(data->stack_a);
		free_stack(data->stack_b);
		return (-1);
	}
	data->stack_b->values = malloc(data->total_size * sizeof(int));
	if (!data->stack_b->values)
	{
		free_stack_and_vals(data->stack_a);
		free_stack(data->stack_b);
		return (-1);
	}
	return (0);
}
