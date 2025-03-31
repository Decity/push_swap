/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:12:17 by elie              #+#    #+#             */
/*   Updated: 2024/07/05 09:48:34 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	is_sorted(t_stack *stack);
bool	is_valid_int(const char *str);
bool	has_valid_values(t_data *data);
bool	has_no_duplicates(t_stack *stack);
bool	is_overflow(const char *str);

bool	is_sorted(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size - 1)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->values[i] > stack->values[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	is_valid_int(const char *str)
{
	if (*str == '-')
		++str;
	if (!*str)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		else
			++str;
	}
	return (true);
}

bool	has_valid_values(t_data *data)
{
	int		i;
	char	**values;

	i = 0;
	values = data->values_as_str;
	while (values[i])
	{
		if (is_valid_int(values[i]) == false)
			return (false);
		if (ft_atol(values[i]) > INT_MAX || ft_atol(values[i]) < INT_MIN)
			return (false);
		if (is_overflow(values[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	has_no_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size - 1)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->values[i] == stack->values[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	is_overflow(const char *str)
{
	int		i;
	int64_t	num;

	num = 0;
	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (((num * 10) + (str[i] - '0')) < num)
			return (true);
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (false);
}
