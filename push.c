/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:41:00 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/20 21:57:22 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *node1, t_stack *node2)
{
	t_stack	*tmp;
	
	tmp = node2->next;
	node2->next = node1;
	node2 = tmp;
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_printf("pa");
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_printf("pb");
}
