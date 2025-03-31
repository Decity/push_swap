/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:42:06 by elie              #+#    #+#             */
/*   Updated: 2024/07/04 22:26:28 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_stack *stack);
void	reverse_rotate_a(t_data *data);
void	reverse_rotate_b(t_data *data);
void	reverse_rotate_r(t_data *data);

void	reverse_rotate(t_stack *stack)
{
	int		i;
	int		temp;
	int		index_bot;

	index_bot = stack->size - 1;
	temp = stack->values[index_bot];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->values[index_bot - i] = stack->values[index_bot - i - 1];
		i++;
	}
	stack->values[0] = temp;
}

void	reverse_rotate_a(t_data *data)
{
	ft_printf("rra\n");
	reverse_rotate(data->stack_a);
}

void	reverse_rotate_b(t_data *data)
{
	ft_printf("rrb\n");
	reverse_rotate(data->stack_b);
}

void	reverse_rotate_r(t_data *data)
{
	ft_printf("rrr\n");
	reverse_rotate(data->stack_a);
	reverse_rotate(data->stack_b);
}
