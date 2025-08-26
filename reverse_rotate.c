/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:41:45 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/26 16:27:34 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **n)
{
	t_stack	*u;
	t_stack	*a;

	a = (*n);
	while (a->next->next)
		a = a->next;
	u = a->next;
	a->next = NULL;
	u->next = *n;
	*n = u;
}

void	rra(t_stack **n)
{
	reverse_rotate(n);
	ft_printf("rra\n");
}

void	rrb(t_stack **n)
{
	reverse_rotate(n);
	ft_printf("rrb\n");
}

void	rrr(t_stack **node1, t_stack **node2)
{
	reverse_rotate(node1);
	reverse_rotate(node2);
	ft_printf("rrr\n");
}
