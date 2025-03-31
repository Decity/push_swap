/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:54:00 by elie              #+#    #+#             */
/*   Updated: 2024/07/03 09:17:23 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *stack);
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	swap_s(t_data *data);

void	swap(t_stack *stack)
{
	int	to_swap;

	if (stack->size < 2)
		return ;
	to_swap = stack->values[0];
	stack->values[0] = stack->values[1];
	stack->values[1] = to_swap;
}

void	swap_a(t_data *data)
{
	ft_printf("sa\n");
	swap(data->stack_a);
}

void	swap_b(t_data *data)
{
	ft_printf("sb\n");
	swap(data->stack_b);
}

void	swap_s(t_data *data)
{
	ft_printf("ss\n");
	swap(data->stack_a);
	swap(data->stack_b);
}
