/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:54:00 by elie              #+#    #+#             */
/*   Updated: 2024/07/04 15:16:45 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack *src, t_stack *dst);
void	push_a(t_data *data);
void	push_b(t_data *data);

void	push(t_stack *src, t_stack *dst)
{
	int	i;

	i = 0;
	if (dst->size != 0)
		dst->index_bot++;
	dst->size++;
	while (i < dst->index_bot)
	{
		dst->values[dst->index_bot - i] = dst->values[dst->index_bot - i - 1];
		i++;
	}
	dst->values[0] = src->values[0];
	i = 0;
	while (i < src->index_bot)
	{
		src->values[i] = src->values[i + 1];
		i++;
	}
	if (src->size >= 2)
		src->index_bot--;
	src->size--;
}

void	push_a(t_data *data)
{
	if (data->stack_b->size == 0)
		return ;
	ft_printf("pa\n");
	push(data->stack_b, data->stack_a);
}

void	push_b(t_data *data)
{
	if (data->stack_a->size == 0)
		return ;
	ft_printf("pb\n");
	push(data->stack_a, data->stack_b);
}
