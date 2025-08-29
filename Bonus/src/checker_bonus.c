/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:13:59 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/22 11:13:35 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

static void	construct_input_string(int ac, char **av, t_data *data)
{
	int		i;
	char	*trimmed;
	char	*temp;

	i = 0;
	data->str = NULL;
	while (++i < ac)
	{
		trimmed = ft_strtrim(av[i], " ");
		if (!trimmed || !trimmed[0])
			return (free(trimmed), free(data->str), handle_error());
		temp = data->str;
		data->str = ft_strjoin(temp, trimmed);
		free(temp);
		free(trimmed);
		if (!data->str)
			return (free(temp), handle_error());
		temp = data->str;
		data->str = ft_strjoin(temp, " ");
		free(temp);
		if (!data->str)
			return (free(temp), handle_error());
	}
}

int	validate_input(int ac, char **av, t_data *data)
{
	construct_input_string(ac, av, data);
	if (!input_valid(data))
		return (free(data->str), free_double_(data->num), 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	data;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (handle_error(), 0);
	if (!validate_input(ac, av, &data))
		return (handle_error(), 0);
	stack_a = init_stack(&stack_a, &data);
	read_and_execute(&stack_a, &stack_b);
	free_data(&data);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
