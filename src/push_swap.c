/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:55:47 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/30 00:55:40 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*stack_fill(char *number, t_stack *stack_a)
{
	t_stack	*node;

	node = NULL;
	if (!check_number(number) || !check_min_max(number))
		return (ft_all(&stack_a, NULL, NULL), NULL);
	node = ft_lstnew(ft_atol(number));
	if (!node)
		return (free(node), NULL);
	if (!check_equal(stack_a, node))
		return (ft_all(&stack_a, node, NULL), NULL);
	ft_lstadd_back(&stack_a, node);
	return (stack_a);
}

static t_stack	*push_swap(char **args, t_stack *stack_a, int i, int j)
{
	char	**splited;

	splited = NULL;
	j = 1;
	while (args[j])
	{
		splited = ft_split(args[j], ' ');
		if (!splited)
			return (ft_all(&stack_a, NULL, splited), NULL);
		i = 0;
		while (splited[i])
		{
			stack_a = stack_fill(splited[i], stack_a);
			i++;
		}
		ft_free_str(splited);
		j++;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 2)
	{
		stack_a = push_swap(argv, stack_a, 0, 0);
		ordenate_index(&stack_a);
		radix_pass(&stack_a, &stack_b);
		if (stack_a)
			free_list(&stack_a);
		if (stack_b)
			free_list(&stack_b);
	}
	return (0);
}
