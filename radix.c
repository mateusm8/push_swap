/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:49:08 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/26 22:41:53 by matmagal         ###   ########.fr       */
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

int	max_index_value(t_stack **node)
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

int	bit_check(int index)
{
	int i;
	
	i = 0;
	while ((index >> i) != 0)
		i++;
	return (i);
}
