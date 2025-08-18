/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:55:47 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/18 20:03:15 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	char	x[] = {"3 5 6 7 90 35 631 642 -2147483648 2147483647"};
	char	**splited;
	int	i;
	t_stack	*stack_a = NULL;
	
	splited = ft_split(x, ' ');
	i = 0;
	while (splited[i])
	{
		t_stack	*node = ft_lstnew(ft_atol(splited[i]));
		ft_lstadd_back(&stack_a, node);
		i++;
	}
	while (stack_a)
	{
		printf("%d\n", stack_a->data);
		stack_a = stack_a->next;
	}
	return (0);
}

// while (stack_a)
// {
// 	if (stack_a->data = node->data)
// 		return (-1);
// 	stack_a = stack_a->next;
// }