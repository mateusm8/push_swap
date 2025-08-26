/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:55:47 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/26 21:46:06 by matmagal         ###   ########.fr       */
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
	t_stack *tmp;

	splited = NULL;
	if (argc < 2)
		return (0);
	j = 1;
	while (argv[j])
	{
		splited = ft_split(argv[j], ' ');
		if (!splited)
			return (printf("Error\n"));
		i = 0;
		while (splited[i])
		{
			if (!check_number(splited[i]) || !check_min_max(splited[i]))
				return (ft_all(&stack_a, NULL, splited));
			node = ft_lstnew(ft_atol(splited[i]));
			if (!check_equal(stack_a, node))
				return (ft_all(&stack_a, node, splited));
			ft_lstadd_back(&stack_a, node);
			i++;
		}
		ft_free_str(splited);
		j++;
	}
	tmp = stack_a;
	ordenate_index(&stack_a);
	while (stack_a)
	{
		ft_printf("Valor do dado: %d\nValor do index: %d\n", stack_a->data, stack_a->index);
		stack_a = stack_a->next;
	}
	free_list(&tmp);
	return (0);
}
