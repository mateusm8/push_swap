/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:41:45 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/21 17:19:54 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **node)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp2 = (*node);
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *node;
	*node = tmp;
}

void	rra(t_stack *node)
{
	reverse_rotate(&node);
	ft_printf("rra\n");
}

void	rrb(t_stack *node)
{
	reverse_rotate(&node);
	ft_printf("rrb\n");
}

void	rrr(t_stack *node1, t_stack *node2)
{
	reverse_rotate(&node1);
	reverse_rotate(&node2);
	ft_printf("rrr\n");
}
