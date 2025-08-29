/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:49:08 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/29 18:37:28 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ordenate_index(t_stack **node)
{
	int		i;
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp2 = (*node);
	while (tmp2)
	{
		i = 0;
		tmp = (*node);
		while (tmp)
		{
			if (tmp2->data > tmp->data)
				i++;
			tmp = tmp->next;
		}
		tmp2->index = i;
		tmp2 = tmp2->next;
	}
}

static int	max_index_value(t_stack **node)
{
	int		i;
	t_stack	*tmp;

	tmp = (*node);
	i = 0;
	while (tmp)
	{
		if (tmp->index > i)
			i = tmp->index;
		tmp = tmp->next;
	}
	return (i);
}

static int	bit_check(int index)
{
	int	i;

	i = 0;
	while ((index >> i) != 0)
		i++;
	return (i);
}

void	radix_pass(t_stack **stack_a, t_stack **stack_b)
{
	int	max_bits;
	int	i;
	int	j;
	int	lst_size;

	i = 0;
	lst_size = ft_lstsize(*stack_a);
	max_bits = bit_check(max_index_value(stack_a));
	while (i < max_bits)
	{
		j = 0;
		while (j < lst_size)
		{
			if (!(((*stack_a)->index >> i) & 1))
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
