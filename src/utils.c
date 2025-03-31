/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:47:55 by elie              #+#    #+#             */
/*   Updated: 2024/07/03 12:14:01 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_highest_value(t_stack *stack)
{
	int	i;
	int	highest_value;

	i = 0;
	highest_value = stack->values[0];
	while (i < stack->size)
	{
		if (stack->values[i] > highest_value)
			highest_value = stack->values[i];
		i++;
	}
	return (highest_value);
}

int	get_lowest_value(t_stack *stack)
{
	int	i;
	int	lowest_value;

	i = 0;
	lowest_value = stack->values[0];
	while (i < stack->size)
	{
		if (stack->values[i] < lowest_value)
			lowest_value = stack->values[i];
		i++;
	}
	return (lowest_value);
}

int	get_second_lowest_value(t_stack *stack)
{
	int	i;
	int	lowest_value;
	int	second_lowest_value;

	i = 0;
	lowest_value = get_lowest_value(stack);
	second_lowest_value = stack->values[0];
	if (stack->values[0] == lowest_value)
		second_lowest_value = stack->values[1];
	while (i < stack->size)
	{
		if (stack->values[i] > lowest_value
			&& stack->values[i] < second_lowest_value)
			second_lowest_value = stack->values[i];
		i++;
	}
	return (second_lowest_value);
}

int	get_bits(t_stack *stack)
{
	int	highest_value;
	int	max_bits;

	highest_value = get_highest_value(stack);
	max_bits = 0;
	while (highest_value > 0)
	{
		highest_value = highest_value >> 1;
		max_bits++;
	}
	return (max_bits);
}
