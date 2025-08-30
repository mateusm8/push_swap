/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:55:47 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/30 03:48:28 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_fill(char *number, t_stack **stack_a)
{
	t_stack	*node;

	node = NULL;
	if (!check_number(number) || !check_min_max(number))
		ft_all(stack_a, NULL, NULL);
	node = ft_lstnew(ft_atol(number));
	if (!node)
	{
		free(node);
		return ;
	}
	if (!check_equal(*stack_a, node))
		ft_all(stack_a, NULL, NULL);
	ft_lstadd_back(stack_a, node);
}

void	push_swap(char **args, t_stack **stack_a, int i, int j)
{
	char	**splited;

	splited = NULL;
	j = 1;
	while (args[j])
	{
		splited = ft_split(args[j], ' ');
		if (!splited)
			ft_all(stack_a, NULL, splited);
		i = 0;
		while (splited[i])
		{
			stack_fill(splited[i], stack_a);
			i++;
		}
		ft_free_str(splited);
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 2)
	{
		push_swap(argv, &stack_a, 0, 0);
		if (ordenate_checker(&stack_a))
			return (free_list(&stack_a), 0);
		if (argc > 2 && argc < 7)
			hard_coding(&stack_a, &stack_b);
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
