/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:00:52 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/22 11:12:10 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int			size;
	t_element	element;

	size = size_stack(*stack_a);
	if (size == 1)
		return ;
	else if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else if (size > 5 && size <= 100)
	{
		element.chunk_size = 16;
		sort_chunk(stack_a, stack_b, &element);
	}
	else if (size > 100)
	{
		element.chunk_size = 32;
		sort_chunk(stack_a, stack_b, &element);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	data;

	stack_b = NULL;
	stack_a = NULL;
	data.str = NULL;
	if (ac < 2)
		return (0);
	if (!validate_input(ac, av, &data))
		return (handle_error(), 0);
	stack_a = init_stack(&stack_a, &data);
	if (is_sorted(stack_a))
		return (free_stack(&stack_a), free_data(&data), 0);
	sort_stack(&stack_a, &stack_b);
	free_data(&data);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
