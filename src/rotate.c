/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:54:00 by elie              #+#    #+#             */
/*   Updated: 2024/07/02 16:26:49 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_stack *stack);
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	rotate_r(t_data *data);

void	rotate(t_stack *stack)
{
	int		i;
	int		temp;
	int		index_bot;

	index_bot = stack->size - 1;
	temp = stack->values[0];
	i = 0;
	while (i < index_bot)
	{
		stack->values[i] = stack->values[i + 1];
		i++;
	}
	stack->values[index_bot] = temp;
}

void	rotate_a(t_data *data)
{
	ft_printf("ra\n");
	rotate(data->stack_a);
}

void	rotate_b(t_data *data)
{
	ft_printf("rb\n");
	rotate(data->stack_b);
}

void	rotate_r(t_data *data)
{
	ft_printf("rr\n");
	rotate(data->stack_a);
	rotate(data->stack_b);
}
