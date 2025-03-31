/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:47:55 by elie              #+#    #+#             */
/*   Updated: 2024/07/04 22:01:47 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	process_arguments(int argc, char **argv, t_data *data)
{
	int		i;

	if (argc == 1)
		return (-1);
	if (ft_strlen(argv[1]) == 0)
		push_swap_error();
	if (argc == 2)
	{
		data->values_as_str = ft_split(argv[1], ' ');
		if (!data->values_as_str || !data->values_as_str[0])
			push_swap_error();
	}
	else
		data->values_as_str = &argv[1];
	i = 0;
	while (data->values_as_str[i])
		i++;
	data->total_size = i;
	data->argc = argc;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (process_arguments(argc, argv, &data) == -1)
		return (0);
	init_stacks(&data);
	sort(&data);
	free_stacks_and_vals(&data);
	return (0);
}
