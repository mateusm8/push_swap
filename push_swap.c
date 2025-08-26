/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:55:47 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/26 16:25:32 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**splited;
	int		i;
	int		j;
	t_stack	*stack_a = NULL;
	// t_stack	*stack_b = NULL;
	t_stack	*node;

	splited = NULL;
	if (argc < 2)
		return (0);
	j = 1;
	while (argv[j])
	{
		splited = ft_split(argv[j], ' ');
		i = 0;
		while (splited[i])
		{
			if (!check_number(splited[i]) || !check_min_max(splited[i]))
				return (printf("Error"));
			node = ft_lstnew(ft_atol(splited[i]));
			if (!check_equal(stack_a, node))
				return (printf("Numero repetido"));
			ft_lstadd_back(&stack_a, node);
			i++;
		}
		j++;
	}
	rra(&stack_a);
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->data);
		stack_a = stack_a->next;
	}
	return (0);
}
