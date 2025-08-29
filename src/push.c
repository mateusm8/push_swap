/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:41:00 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/27 19:40:44 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **node1, t_stack **node2)
{
	t_stack	*tmp;

	if (!*node2)
		return ;
	tmp = *node2;
	*node2 = (*node2)->next;
	tmp->next = *node1;
	*node1 = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pb\n");
}
