/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:55:47 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/31 18:37:22 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_fill(char **number, t_stack **stack_a)
{
	t_stack	*node;
	int		i;

	node = NULL;
	i = 0;
	while (number[i])
	{
		if (!check_number(number[i]) || !check_min_max(number[i]))
			ft_all(stack_a, NULL, number);
		node = ft_lstnew(ft_atol(number[i]));
		if (!node)
			ft_all(stack_a, node, number);
		if (!check_equal(*stack_a, node))
			ft_all(stack_a, node, number);
		ft_lstadd_back(stack_a, node);
		i++;
	}
}

void	push_swap(char **args, t_stack **stack_a, int j)
{
	char	**splited;

	splited = NULL;
	j = 1;
	while (args[j])
	{
		splited = ft_split(args[j], ' ');
		if (!splited)
			ft_all(stack_a, NULL, splited);
		stack_fill(splited, stack_a);
		ft_free_str(splited);
		j++;
	}
}

int	main(int argc, char **argv)
{
	static t_stack	*stack_a;
	static t_stack	*stack_b;

	if (argc > 2)
	{
		push_swap(argv, &stack_a, 0);
		if (ordenate_checker(&stack_a))
			return (free_list(&stack_a), 0);
		if (argc > 2 && argc < 7)
			sort(&stack_a, &stack_b);
		else
		{
			ordenate_index(&stack_a);
			radix_pass(&stack_a, &stack_b);
		}
		if (stack_a)
			free_list(&stack_a);
		if (stack_b)
			free_list(&stack_b);
	}
	if (argc == 2 && (!check_number(argv[1]) || !check_min_max(argv[1])))
		ft_all(&stack_a, NULL, NULL);
	return (0);
}
