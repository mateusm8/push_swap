/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:55:47 by matmagal          #+#    #+#             */
/*   Updated: 2025/09/18 20:15:23 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	tab_space_check(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] != ' ' && arg[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

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
		if (args[j][0] == '\0' || !tab_space_check(args[j]))
			ft_all(stack_a, NULL, NULL);
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

	if (argc > 1)
	{
		push_swap(argv, &stack_a, 0);
		if (ordenate_checker(&stack_a))
			return (free_list(&stack_a), 0);
		if (ft_lstsize(stack_a) > 1 && ft_lstsize(stack_a) < 6)
			sort(&stack_a, &stack_b);
		else if (ft_lstsize(stack_a) == 1
			&& (!check_number(argv[1]) || !check_min_max(argv[1])))
			ft_all(&stack_a, NULL, NULL);
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
	return (0);
}
