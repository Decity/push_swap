/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:24:09 by ebayat            #+#    #+#             */
/*   Updated: 2024/07/04 15:15:22 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack *stack);
void	free_stack_and_vals(t_stack *stack);
void	free_stacks_and_vals(t_data *data);
void	free_vals(t_data *data);

void	free_stack(t_stack *stack)
{
	free(stack);
	stack = NULL;
}

void	free_stack_and_vals(t_stack *stack)
{
	free(stack->values);
	stack->values = NULL;
	free_stack(stack);
}

void	free_stacks_and_vals(t_data *data)
{
	free_stack_and_vals(data->stack_a);
	free_stack_and_vals(data->stack_b);
	free_vals(data);
}

void	free_vals(t_data *data)
{
	int	i;

	i = 0;
	if (data->argc == 2)
	{
		while (data->values_as_str[i])
		{
			free(data->values_as_str[i]);
			data->values_as_str[i] = NULL;
			i++;
		}
		free(data->values_as_str);
	}
}
